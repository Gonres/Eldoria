//
// Created by Lukyn on 14.12.2024.
//

#include "shop.h"

#include "../domain/value_objects/screen.h"
#include "../tools/keyboard_key.h"

Shop::Shop(const std::function<void(Screen screen)> &changeScreenCallback) {
    m_scene = new Scenes();
    m_changeScreenCallback = changeScreenCallback;
    //Items to buy-creation
    //Weapons:
    m_warriorWeapon1 = new Weapon(10, 1200);
    m_warriorWeapon2 = new Weapon(15, 1800);
    m_warriorWeapon3 = new Weapon(25, 3000);
    m_archerWeapon1 = new Weapon(10, 1200);
    m_archerWeapon2 = new Weapon(13, 1700);
    m_archerWeapon3 = new Weapon(15, 2100);
    m_mageWeapon1 = new Weapon(2, 1200);
    m_mageWeapon2 = new Weapon(3, 1800);
    m_mageWeapon3 = new Weapon(15, 4000);
    //Armors:
    m_warriorArmor1 = new Armor(5, 1000);
    m_warriorArmor2 = new Armor(7, 2400);
    m_warriorArmor3 = new Armor(10, 5000);
    m_archerArmor1 = new Armor(4, 1000);
    m_archerArmor2 = new Armor(6, 1800);
    m_archerArmor3 = new Armor(9, 3500);
    m_mageArmor1 = new Armor(2, 1200);
    m_mageArmor2 = new Armor(4, 2000);
    m_mageArmor3 = new Armor(8, 3500);
    //Potions:
    m_potion = new Potion();
}

Shop::~Shop() {
    delete m_scene;
}

//Functionality
void Shop::changeScreen(const Screen newScreen) {
    m_changeScreenCallback(newScreen);
}

void Shop::buyWeapon(Player *player, Weapon *weapon) {
    if (!player->weaponOwned(weapon)) {
        if (player->getCoins() - weapon->getPrice() >= 0) {
            player->removeCoins(weapon->getPrice());
            player->addWeapon(weapon);
        }
    }
}

void Shop::buyArmor(Player *player, Armor *armor) {
    if (!player->armorOwned(armor)) {
        if (player->getCoins() - armor->getPrice() >= 0) {
            player->removeCoins(armor->getPrice());
            player->addArmor(armor);
        }
    }
}

void Shop::buyPotion(Player *player, Potion *potion) {
    if (player->getCoins() - potion->getPrice() >= 0) {
        player->removeCoins(potion->getPrice());
        player->addPotion(potion);
    }
}

void Shop::confirmSelectionShopMain(int selected) {
    switch (selected) {
        case 0:
            changeScreen(Screen::shopWeapons);
            break;
        case 1:
            changeScreen(Screen::shopArmor);
            break;
        case 2:
            changeScreen(Screen::shopPotions);
            break;
        case 3:
            if (isKeyDown(ENTER)) {
                changeScreen(Screen::game);
            }
            break;
        default: break;
    }
}

void Shop::confirmSelectionShopWeapons(int selected, Player *player) {
    if (isKeyDown(ENTER)) {
        switch (selected) {
            case 0:
                switch (player->getRole()) {
                    case Role::warrior:
                        buyWeapon(player, m_warriorWeapon1);
                        changeScreen(Screen::shopWeapons);
                        break;
                    case Role::archer:
                        buyWeapon(player, m_archerWeapon1);
                        changeScreen(Screen::shopWeapons);
                        break;
                    case Role::mage:
                        buyWeapon(player, m_mageWeapon1);
                        changeScreen(Screen::shopWeapons);
                        break;
                }
                break;
            case 1:
                switch (player->getRole()) {
                    case Role::warrior:
                        buyWeapon(player, m_warriorWeapon2);
                        changeScreen(Screen::shopWeapons);
                        break;
                    case Role::archer:
                        buyWeapon(player, m_archerWeapon2);
                        changeScreen(Screen::shopWeapons);
                        break;
                    case Role::mage:
                        buyWeapon(player, m_mageWeapon2);
                        changeScreen(Screen::shopWeapons);
                        break;
                }
                break;
            case 2:
                switch (player->getRole()) {
                    case Role::warrior:
                        buyWeapon(player, m_warriorWeapon3);
                        changeScreen(Screen::shopWeapons);
                        break;
                    case Role::archer:
                        buyWeapon(player, m_archerWeapon3);
                        changeScreen(Screen::shopWeapons);
                        break;
                    case Role::mage:
                        buyWeapon(player, m_mageWeapon3);
                        changeScreen(Screen::shopWeapons);
                        break;
                }
                break;
            default: break;
        }
    }
}

void Shop::confirmSelectionShopArmor(int selected, Player *player) {
    if (isKeyDown(ENTER)) {
        switch (selected) {
            case 0:
                switch (player->getRole()) {
                    case Role::warrior:
                        buyArmor(player, m_warriorArmor1);
                        changeScreen(Screen::shopArmor);
                        break;
                    case Role::archer:
                        buyArmor(player, m_archerArmor1);
                        changeScreen(Screen::shopArmor);
                        break;
                    case Role::mage:
                        buyArmor(player, m_mageArmor1);
                        changeScreen(Screen::shopArmor);
                        break;
                }
                break;
            case 1:
                switch (player->getRole()) {
                    case Role::warrior:
                        buyArmor(player, m_warriorArmor2);
                        changeScreen(Screen::shopArmor);
                        break;
                    case Role::archer:
                        buyArmor(player, m_archerArmor2);
                        changeScreen(Screen::shopArmor);
                        break;
                    case Role::mage:
                        buyArmor(player, m_mageArmor2);
                        changeScreen(Screen::shopArmor);
                        break;
                }
                break;
            case 2:
                switch (player->getRole()) {
                    case Role::warrior:
                        buyArmor(player, m_warriorArmor3);
                        changeScreen(Screen::shopArmor);
                        break;
                    case Role::archer:
                        buyArmor(player, m_archerArmor3);
                        changeScreen(Screen::shopArmor);
                        break;
                    case Role::mage:
                        buyArmor(player, m_mageArmor3);
                        changeScreen(Screen::shopArmor);
                        break;
                }
                break;
            default: break;
        }
    }
}

void Shop::confirmSelectionShopPotions(int selected, Player *player) {
    if (isKeyDown(ENTER)) {
        switch (selected) {
            case 2:
                buyPotion(player, m_potion);
                changeScreen(Screen::shopPotions);
                break;
            default: break;
        }
    }
}

//Scenes
void Shop::displayShopHeader() const {
    m_scene->sceneShopHeader();
}

void Shop::displayShopWeaponHeader(Player *player) const {
    GlobalSettings::clearConsoleOnNewScreen();
    m_scene->sceneShopWeaponHeader(player);
}

void Shop::displayShopArmorHeader(Player *player) const {
    GlobalSettings::clearConsoleOnNewScreen();
    m_scene->sceneShopArmorHeader(player);
}

void Shop::displayShopPotionHeader(Player *player) const {
    m_scene->sceneShopPotionHeader(player);
}

void Shop::displayShopHint() const {
    m_scene->sceneShopHint();
}

void Shop::displayShopMain(int selected) const {
    displayShopHeader();
    switch (selected) {
        case 0:
            m_scene->sceneShopMainSelectedWeapons();
            break;
        case 1:
            m_scene->sceneShopMainSelectedArmor();
            break;
        case 2:
            m_scene->sceneShopMainSelectedPotions();
            break;
        case 3:
            m_scene->sceneShopMainSelectedExit();
            break;
        default: break;
    }
    displayShopHint();
}

void Shop::displayShopWeapons(int selected, Player *player) const {
    displayShopWeaponHeader(player);
    switch (selected) {
        case 0:
            switch (player->getRole()) {
                case Role::warrior:
                    m_scene->sceneShopWeaponsSelectedWeapon1(player, m_warriorWeapon1);
                    break;
                case Role::archer:
                    m_scene->sceneShopWeaponsSelectedWeapon1(player, m_archerWeapon1);
                    break;
                case Role::mage:
                    m_scene->sceneShopWeaponsSelectedWeapon1(player, m_mageWeapon1);
                    break;
            }
            break;
        case 1:
            switch (player->getRole()) {
                case Role::warrior:
                    m_scene->sceneShopWeaponsSelectedWeapon2(player, m_warriorWeapon2);
                    break;
                case Role::archer:
                    m_scene->sceneShopWeaponsSelectedWeapon2(player, m_archerWeapon2);
                    break;
                case Role::mage:
                    m_scene->sceneShopWeaponsSelectedWeapon2(player, m_mageWeapon2);
                    break;
            }
            break;
        case 2:
            switch (player->getRole()) {
                case Role::warrior:
                    m_scene->sceneShopWeaponsSelectedWeapon3(player, m_warriorWeapon3);
                    break;
                case Role::archer:
                    m_scene->sceneShopWeaponsSelectedWeapon3(player, m_archerWeapon3);
                    break;
                case Role::mage:
                    m_scene->sceneShopWeaponsSelectedWeapon3(player, m_mageWeapon3);
                    break;
            }
            break;
        default: break;
    }
}

void Shop::displayShopArmor(int selected, Player *player) const {
    displayShopArmorHeader(player);
    switch (selected) {
        case 0:
            switch (player->getRole()) {
                case Role::warrior:
                    m_scene->sceneShopArmorSelectedArmor1(player, m_warriorArmor1);
                    break;
                case Role::archer:
                    m_scene->sceneShopArmorSelectedArmor1(player, m_archerArmor1);
                    break;
                case Role::mage:
                    m_scene->sceneShopArmorSelectedArmor1(player, m_mageArmor1);
                    break;
            }
            break;
        case 1:
            switch (player->getRole()) {
                case Role::warrior:
                    m_scene->sceneShopArmorSelectedArmor2(player, m_warriorArmor2);
                    break;
                case Role::archer:
                    m_scene->sceneShopArmorSelectedArmor2(player, m_archerArmor2);
                    break;
                case Role::mage:
                    m_scene->sceneShopArmorSelectedArmor2(player, m_mageArmor2);
                    break;
            }
            break;
        case 2:
            switch (player->getRole()) {
                case Role::warrior:
                    m_scene->sceneShopArmorSelectedArmor3(player, m_warriorArmor3);
                    break;
                case Role::archer:
                    m_scene->sceneShopArmorSelectedArmor3(player, m_archerArmor3);
                    break;
                case Role::mage:
                    m_scene->sceneShopArmorSelectedArmor3(player, m_mageArmor3);
                    break;
            }
            break;
        default: break;
    }
}

void Shop::displayShopPotions(int selected, Player *player) const {
    displayShopPotionHeader(player);
    switch (selected) {
        case 2:
            m_scene->sceneShopPotionsSelectedPotion1(m_potion);
            break;
        default: break;
    }
}
