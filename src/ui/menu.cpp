//
// Created by Lukyn on 26.11.2024.
//

#include "menu.h"

#include <iostream>

#include "../application.h"
#include "../tools/global_settings.h"
#include "../tools/keyboard_key.h"

Menu::Menu() {
    m_selected = 0;
    m_currentScreen = Screen::mainMenu;
    m_scene = new Scenes();
    m_shop = new Shop([this](const Screen screen) { changeScreen(screen); });
    playerRole = Role::warrior;
    m_startedGameForTheFirstTime = false;
}

Menu::~Menu() {
    delete m_scene;
    delete m_shop;
}

void Menu::changeScreenNormal(const Screen newScreen) {
    m_selected = 0;
    GlobalSettings::clearConsoleOnNewScreen();
    m_currentScreen = newScreen;
}

void Menu::changeScreen(const Screen newScreen) {
    if (m_currentScreen == Screen::shopMain && isKeyDown(ESCAPE)) {
        return;
    }
    if ((m_currentScreen == Screen::shopArmor || m_currentScreen == Screen::shopPotions || m_currentScreen ==
         Screen::shopWeapons) && isKeyDown(ESCAPE)) {
        GlobalSettings::clearConsoleOnNewScreen();
        m_selected = 0;
        m_currentScreen = Screen::shopMain;
        return;
    }
    if (m_currentScreen != Screen::mainMenu && isKeyDown(ESCAPE)) {
        GlobalSettings::clearConsoleOnNewScreen();
        m_selected = 0;
        m_currentScreen = Screen::mainMenu;
    } else if (isKeyDown(ENTER) && m_currentScreen != Screen::game) {
        GlobalSettings::clearConsoleOnNewScreen();
        m_currentScreen = newScreen;
    }
}

Screen Menu::getCurrentScreen() const {
    return m_currentScreen;
}

Shop *Menu::getShop() const {
    return m_shop;
}

int Menu::getSelected() const {
    return m_selected;
}

Role Menu::chosenRole() const {
    return playerRole;
}

void Menu::handleMenuInput(Player *player) {
    switch (m_currentScreen) {
        case Screen::mainMenu:
            if (isKeyDown(ESCAPE)) {
                Application::shutdown();
                break;
            }
            navigateMenu(4);
            confirmSelectionMainMenu();
            break;
        case Screen::roleMenu:
            navigateMenu(3);
            confirmSelectionRoleMenu();
            break;
        case Screen::creditsMenu: // NOLINT
            navigateMenu(1);
            break;
        case Screen::howToPlayMenu:
            navigateMenu(1);
            break;
        case Screen::shopMain:
            navigateMenu(4);
            m_shop->confirmSelectionShopMain(m_selected);
            break;
        case Screen::shopArmor:
            navigateMenu(3);
            m_shop->confirmSelectionShopArmor(m_selected, player);
            break;
        case Screen::shopPotions:
            navigateMenu(1);
            m_shop->confirmSelectionShopPotions(m_selected, player);
            break;
        case Screen::shopWeapons:
            navigateMenu(3);
            m_shop->confirmSelectionShopWeapons(m_selected, player);
            break;
        case Screen::cutscenes:
            confirmCutscene();
            break;
        case Screen::endScenes:
            confirmEndScenes();
            break;
        case Screen::death:
            if (isKeyDown('\0') || isKeyDown(ENTER) || isKeyDown(ESCAPE)) {
                Application::shutdown();
                break;
            }
            break;
        default: navigateMenu(4);
    }
}

void Menu::headerMenu() const {
    m_scene->sceneHeaderMenu();
}

void Menu::smallHeaderMenu() const {
    m_scene->sceneSmallHeaderMenu();
}

void Menu::displayMainMenu() const {
    headerMenu();
    switch (m_selected) {
        case 0:
            m_scene->sceneMainSelectedPlay();
            break;
        case 1:
            m_scene->sceneMainSelectedCredits();
            break;
        case 2:
            m_scene->sceneMainSelectedHTP();
            break;
        case 3:
            m_scene->sceneMainSelectedExit();
            break;
        default: break;
    }
}

void Menu::displayCreditsMenu() const {
    m_scene->sceneCreditsMenu();
}

void Menu::displayHowToPlay() const {
    headerMenu();
    m_scene->sceneHTPMenu();
}

void Menu::displayRoleMenu() const {
    GlobalSettings::clearConsoleOnNewScreen();
    headerMenu();
    std::cout << "<=== CHOOSE YOUR ROLE ===>\n";
    switch (m_selected) {
        case 0:
            m_scene->sceneRoleSelectedWarrior();
            break;
        case 1:
            m_scene->sceneRoleSelectedArcher();
            break;
        case 2:
            m_scene->sceneRoleSelectedMage();
            break;
        default: break;
    }
}

void Menu::displayCutscenes() const {
    m_scene->printScenes();
}

void Menu::displayDeathScreen() const {
    GlobalSettings::clearConsoleOnNewScreen();
    m_scene->sceneDeathScreen();
}

void Menu::displayEndScenes() const {
    m_scene->printEndGame();
}

void Menu::moveUpMenu(const int selectableItemsOnScreenCount) {
    if (isKeyDown(KEY_W)) {
        m_selected--;
        if (m_selected < 0) {
            m_selected = selectableItemsOnScreenCount - 1;
        }
    }
}

void Menu::moveDownMenu(const int selectableItemsOnScreenCount) {
    if (isKeyDown(KEY_S)) {
        m_selected++;
        if (m_selected >= selectableItemsOnScreenCount) {
            m_selected = 0;
        }
    }
}

void Menu::confirmSelectionMainMenu() {
    switch (m_selected) {
        case 0:
            if (!m_startedGameForTheFirstTime) {
                changeScreen(Screen::roleMenu);
            } else {
                changeScreen(Screen::game);
            }
            break;
        case 1:
            changeScreen(Screen::creditsMenu);
            break;
        case 2:
            changeScreen(Screen::howToPlayMenu);
            break;
        case 3:
            if (isKeyDown(ENTER)) {
                Application::shutdown();
            }
            break;
        default: break;
    }
}

void Menu::confirmSelectionRoleMenu() {
    switch (m_selected) {
        case 0:
            playerRole = Role::warrior;
            break;
        case 1:
            playerRole = Role::archer;
            break;
        case 2:
            playerRole = Role::mage;
            break;
        default:
            break;
    }
    if (isKeyDown(ENTER)) {
        m_startedGameForTheFirstTime = true;
    }
    changeScreen(Screen::cutscenes);
}

void Menu::confirmCutscene() {
    GlobalSettings::clearConsoleOnNewScreen();
    m_scene->incrementCurrentScene();
    if (m_scene->getCurrentScene() > 3) {
        changeScreen(Screen::game);
        m_scene->setCurrentScene(0);
    }
}

void Menu::confirmEndScenes() const {
    m_scene->incrementCurrentScene();
    GlobalSettings::clearConsoleOnNewScreen();
    if (m_scene->getCurrentScene() > 2) {
        Application::shutdown();
        m_scene->setCurrentScene(0);
    }
}

void Menu::navigateMenu(const int selectableItemsOnScreenCount) {
    if (selectableItemsOnScreenCount != 1) {
        moveUpMenu(selectableItemsOnScreenCount);
        moveDownMenu(selectableItemsOnScreenCount);
    }
    changeScreen(Screen::mainMenu);
}
