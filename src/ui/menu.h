//
// Created by Lukyn on 26.11.2024.
//

#ifndef MENU_H
#define MENU_H
#include "scenes.h"
#include "shop.h"
#include "../domain/value_objects/screen.h"

class Menu {
public:
    explicit Menu();

    ~Menu();

    void changeScreenNormal(Screen newScreen);

    //Design methods
    void headerMenu() const;

    void smallHeaderMenu() const;

    //Individual screens
    void displayMainMenu() const;

    void displayRoleMenu() const;

    void displayCreditsMenu() const;

    void displayHowToPlay() const;

    void displayCutscenes() const;

    void displayDeathScreen() const;

    void displayEndScenes() const;

    Screen getCurrentScreen() const;

    //Functionality
    void handleMenuInput(Player *player);

    Shop *getShop() const;

    int getSelected() const;

    Role chosenRole() const;

private:
    int m_selected;
    Screen m_currentScreen;
    Scenes *m_scene;
    Shop *m_shop;
    Role playerRole;
    bool m_startedGameForTheFirstTime;

    //Movement
    void navigateMenu(int selectableItemsOnScreenCount);

    void moveUpMenu(int selectableItemsOnScreenCount);

    void moveDownMenu(int selectableItemsOnScreenCount);

    void confirmSelectionMainMenu();

    void confirmSelectionRoleMenu();

    void confirmCutscene();

    void confirmEndScenes() const;

    void changeScreen(Screen newScreen);
};

#endif //MENU_H
