#include "combat.h"

#include <utility>

#include "fight_state.h"
#include "iostream"
#include "passive_state.h"
#include "../domain/entities/player.h"
#include "../tools/color.h"
#include "../tools/global_settings.h"
#include "../tools/keyboard_key.h"

Combat::Combat(Enemy *enemy, Player *player) : enemy(enemy), player(player) {
    this->combatState = std::make_unique<PassiveState>();
    this->randomDamage = enemy->randomDamage();
}

void Combat::setState(std::unique_ptr<CombatState> newState) {
    combatState = std::move(newState);
}

void Combat::startCombat() {
    setState(std::make_unique<FightState>());
    if (!startedCombat) {
        startedCombat = true;
        displayCombatHeader();
    }
    if (isKeyDown(KEY_F)) {
        handleCombatAttack();
    }
    enemy->setAggro(combatState->isAggroed());
}

void Combat::endCombat() {
    setState(std::make_unique<PassiveState>());
    startedCombat = false;
    std::cout << "\r                                              \r";
    enemy->setAggro(combatState->isAggroed());
}

void Combat::update() {
    if ((isPlayerInRange() && isKeyDown(KEY_F)) || enemy->isInRange(
            player->getPosition(), enemy->getPosition())) {
        startCombat();
    }

    if (!enemy->isAggroed() && !enemy->isAlive()) {
        endCombat();
    }
}

void Combat::damageEnemy() const {
    if (player->isInRange(player->getPosition(), enemy->getPosition())) {
        enemy->takeDamage(player->getTotalDamage());
    }
}

void Combat::damagePlayer() const {
    if (Position::isInRangeOfOne(player->getPosition().x, player->getPosition().y,
                                 enemy->getPosition().x, enemy->getPosition().y)) {
        if (player->getTotalDefense() - enemy->getDamage() < 0) {
            player->takeDamage(randomDamage - player->getTotalDefense());
        }
    }
}

void Combat::handleCombat() {
    update();
    combatState->handleCombat(*this);
}

bool Combat::isPlayerInRange() const {
    return player->isInRange(player->getPosition(), enemy->getPosition());
}

void Combat::displayCombatHeader() {
    setColor(Colors::red);
    std::cout << "\r------- IN Combat -------\n";
    setColor(Colors::white);
    std::flush(std::cout);
}

void Combat::handleCombatAttack() const {
    if (Position::isInRangeOfOne(player->getPosition().x, player->getPosition().y,
                                 enemy->getPosition().x, enemy->getPosition().y)) {
        // Both sides deal damage
        std::cout << "\n\rYou hit " << enemyTypeToString(enemy->getEnemyType()) << ". ";
        if (player->getTotalDefense() - randomDamage < 0) {
            std::cout << enemyTypeToString(enemy->getEnemyType()) << " hits you for ";
            setColor(Colors::red);
            std::cout << abs(player->getTotalDefense() - randomDamage);
            setColor(Colors::white);
            std::cout <<
                    " damage.                                                                                     \n";
        } else {
            std::cout << "You defended yourself                                                                     \n";
        }
    } else if (isPlayerInRange()) {
        // Player attacks but is not counterattacked
        std::cout << "\n\rYou hit " << enemyTypeToString(enemy->getEnemyType()) <<
                ".                                                                                          \n";
    }
    std::flush(std::cout);
}
