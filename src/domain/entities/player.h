//
// Created by ivo on 11/16/2024.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <functional>
#include <vector>

#include "entity.h"
#include "../value_objects/role.h"
#include "../value_objects/items/armor.h"
#include "../value_objects/items/potion.h"
#include "../value_objects/items/weapon.h"

class Player : public Entity {
public:
    Player(Role role, int hp, int damage, int armor, int range);

    void checkStatus(const std::function<void()> &changeScreen);

    void levelUp();

    void usePotion();

    int getXp() const;

    int getLevel() const; //XP Level

    int getDamage() const;

    int getMaxHp() const;

    bool weaponOwned(const Weapon *weapon) const;

    bool armorOwned(const Armor *armor) const;

    int getTotalDefense() const; //Methods for fighting

    int getTotalDamage() const; //Methods for fighting

    Role getRole() const;

    void addPotion(Potion *potion);

    void addWeapon(Weapon *weapon);

    void addArmor(Armor *armor);

    void addXp(int xp);

    void addHp(int hp);

    void addMaxHp(int maxHp);

    void addDamage(int damage);

    void addCoins(int coins);

    void removeCoins(int coins);

    int getNumberOfPotions() const;

    int getCoins() const;

    int getRange() const;

private:
    std::vector<Weapon *> weapons;
    std::vector<Armor *> armors;
    std::vector<Potion *> potions;
    int xp;
    int maxHp; //MAX HP you can achieve by healing. It increases with LVL Ups - but not your current HP.
    int level; //XP Level
    int coins;
    Role role;
    int armor;
};

#endif //PLAYER_H
