#include "game.h"

#include <iostream>

#include "combat_system/combat.h"
#include "commands/enemy/loot_enemy.h"
#include "commands/interaction/healing_interaction.h"
#include "commands/interaction/merchant_interaction.h"
#include "commands/interaction/prisoner_interaction.h"
#include "commands/npc/add_prisoner.h"
#include "movement/enemy_movement.h"
#include "movement/player_movement.h"
#include "tools/color.h"

Game::Game() {
    this->player = nullptr;
    this->menu = new Menu();
    this->levels = new Levels();
}

Game::~Game() {
    delete menu;
    delete levels;
    delete player;
}

void Game::render() {
    switch (menu->getCurrentScreen()) {
        case Screen::mainMenu:
            menu->displayMainMenu();
            break;
        case Screen::roleMenu:
            menu->displayRoleMenu();
            break;
        case Screen::creditsMenu:
            menu->displayCreditsMenu();
            break;
        case Screen::howToPlayMenu:
            menu->displayHowToPlay();
            break;
        case Screen::cutscenes:
            menu->displayCutscenes();
            break;
        case Screen::shopMain:
            menu->getShop()->displayShopMain(menu->getSelected());
            break;
        case Screen::shopWeapons:
            menu->getShop()->displayShopWeapons(menu->getSelected(), player);
            break;
        case Screen::shopArmor:
            menu->getShop()->displayShopArmor(menu->getSelected(), player);
            break;
        case Screen::shopPotions:
            menu->getShop()->displayShopPotions(menu->getSelected(), player);
            break;
        case Screen::game:
            initializePlayer();
            player->checkStatus([this] { menu->changeScreenNormal(Screen::death); });
            displayGUI();
            break;
        case Screen::death:
            menu->displayDeathScreen();
            break;
        case Screen::endScenes:
            menu->displayEndScenes();
            break;
    }
}

void Game::handleInputs() const {
    // Handle movement on menu.
    menu->handleMenuInput(player);
    if (!(player && menu->getCurrentScreen() == Screen::game)) {
        return;
    }
    // Handle player movement on the map.
    PlayerMovement(player).movePlayer(levels->getMap(), [this] {
                                          levels->nextLevel(player, [this] {
                                              menu->changeScreenNormal(Screen::endScenes);
                                          });
                                      },
                                      AddEnemy::getEnemies());
    // Handle movement for enemies.
    for (Enemy *enemy: AddEnemy::getEnemies()) {
        Combat(enemy, player).handleCombat();
        if (!AddEnemy::getEnemies().empty() && enemy->isAlive()) {
            EnemyMovement(enemy).moveEnemy(levels->getMap(), player);
            enemy->checkEnemyHp(
                levels->getMap(),
                [this, enemy] { Command::execute(LootEnemy(player, enemy)); }
            );
        }
    }
    // Handle interaction with merchant
    Command::execute(MerchantInteraction(levels->getMerchant()->getMerchant(),
                                         [this] { menu->changeScreenNormal(Screen::shopMain); }, player));
    // Handle interaction with prisoner
    for (Prisoner *prisoner: AddPrisoner::getPrisoners()) {
        Command::execute(PrisonerInteraction(prisoner, levels->getMap(), player));
    }
    // Handle interaction with player's mechanic to heal himself
    Command::execute(HealingInteraction(player));
}

void Game::displayGUI() const {
    menu->smallHeaderMenu();
    displayPlayerProperties();
    levels->loadAllLevels();
    levels->renderCurrentLevel();
    displayHelp();
}

void Game::displayHelp() const {
    std::cout << "\n[WASD] Move around" << "\n";
    // Set the color based on whether any enemy is in range.
    levels->isAnyEnemyInRange(player)
        ? setColor(Colors::yellow)
        : setColor(Colors::white);
    std::cout << "[F] Fight" << "\n";
    setColor(Colors::white);
    levels->isAnyPrisonerInRange(player) ||
    (levels->getMerchant()->getMerchant() != nullptr && levels->getMerchant()->getMerchant()->
     isAnyMerchantInRange(player->getPosition()))
        ? setColor(Colors::yellow)
        : setColor(Colors::white);
    std::cout << "[E] Interact" << "\n";
    setColor(Colors::white);
    std::cout << "[H] Use Heath Potion" << "\n";
    setColor(Colors::yellow);
    std::cout << "? = Prisoner, ! = Enemy, $ = Merchant" << "\n\n";
    setColor(Colors::white);
    std::cout << "_______________EVENT LOG_______________\n\n";
}

void Game::displayPlayerProperties() const {
    std::cout << "HP: ";
    setColor(Colors::red);
    std::cout << player->getHp();
    setColor(Colors::white);
    std::cout << " / " << player->getMaxHp() << "    \n";
    std::cout << "COINS: ";
    setColor(Colors::yellow);
    std::cout << player->getCoins() << "      \n";
    setColor(Colors::white);
    std::cout << "LVL: " << player->getLevel() << "      -     " << player->getXp() << "/100 XP   \n";
    std::cout << "HEALTH POTIONS: ";
    std::cout << player->getNumberOfPotions() << "  \n";
    std::cout << "CAVE: " << levels->getCurrentLevel() + 1 << " / " << levels->getMaps().size() << "   \n\n";
}

Player *createPlayer(const Role role) {
    Player *warrior = new Player(Role::warrior, 100, 10, 3, 1);
    Player *archer = new Player(Role::archer, 100, 6, 2, 2);
    Player *mage = new Player(Role::mage, 100, 2, 1, 2);
    switch (role) {
        case Role::warrior: return warrior;
        case Role::archer: return archer;
        case Role::mage: return mage;
        default: return warrior;
    }
}

Player *Game::initializePlayer() {
    if (player == nullptr) {
        player = createPlayer(menu->chosenRole());
    }
    return player;
}

