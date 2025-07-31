//
// Created by Lukyn on 14.12.2024.
//

#ifndef SHOP_H
#define SHOP_H
#include <functional>
#include <iostream>
#include "scenes.h"
#include "../tools/global_settings.h"
#include "../domain/entities/player.h"
#include "../domain/value_objects/screen.h"
#include "../domain/value_objects/items/weapon.h"
#include "../domain/value_objects/items/armor.h"
#include "../domain/value_objects/items/potion.h"

class Shop {
    Scenes *m_scene;
    std::function<void(Screen screen)> m_changeScreenCallback;
    //Items to buy:
    Weapon *m_warriorWeapon1;
    Weapon *m_archerWeapon1;
    Weapon *m_mageWeapon1;
    Weapon *m_warriorWeapon2;
    Weapon *m_archerWeapon2;
    Weapon *m_mageWeapon2;
    Weapon *m_warriorWeapon3;
    Weapon *m_archerWeapon3;
    Weapon *m_mageWeapon3;
    Armor *m_warriorArmor1;
    Armor *m_archerArmor1;
    Armor *m_mageArmor1;
    Armor *m_warriorArmor2;
    Armor *m_archerArmor2;
    Armor *m_mageArmor2;
    Armor *m_warriorArmor3;
    Armor *m_archerArmor3;
    Armor *m_mageArmor3;
    Potion *m_potion;

public:
    void confirmSelectionShopMain(int selected);

    void confirmSelectionShopWeapons(int selected, Player *player);

    void confirmSelectionShopArmor(int selected, Player *player);

    void confirmSelectionShopPotions(int selected, Player *player);

    void changeScreen(Screen newScreen);

    Shop(const std::function<void(Screen screen)> &changeScreenCallback);

    ~Shop();

    void buyWeapon(Player *player, Weapon *weapon);

    void buyArmor(Player *player, Armor *armor);

    void buyPotion(Player *player, Potion *potion);

    //Individual screens
    void displayShopHeader() const;

    void displayShopWeaponHeader(Player *player) const;

    void displayShopArmorHeader(Player *player) const;

    void displayShopPotionHeader(Player *player) const;

    void displayShopHint() const;

    void displayShopMain(int selected) const;

    void displayShopWeapons(int selected, Player *player) const;

    void displayShopArmor(int selected, Player *player) const;

    void displayShopPotions(int selected, Player *player) const;
};

#endif //SHOP_H
