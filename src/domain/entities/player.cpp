//
// Created by ivo on 11/16/2024.
//

#include "player.h"

Player::Player(const Role role, const int hp, const int damage, const int armor, const int range)
    : Entity(hp, damage, range, true, Position{5, 1}) {
    this->armors = {};
    this->weapons = {};
    this->potions = {};
    this->role = role;
    this->armor = armor;
    this->range = range;
    this->maxHp = hp;
    this->xp = 0;
    this->level = 1;
    this->coins = 0;
}

void Player::levelUp() {
    level += 1;
    xp -= 100;
    addCoins(150);
    switch (role) {
        case Role::warrior:
            maxHp += 15;
            damage += 5;
            break;
        case Role::archer:
            maxHp += 10;
            if (level % 3 == 0) {
                damage += 3;
            }
            if (level % 4 == 0) {
                range += 1;
            }
            break;
        case Role::mage:
            maxHp += 5;
            damage += 2;
            if (level % 3 == 0) {
                range += 1;
            }
            break;
    }
}

void Player::checkStatus(const std::function<void()> &changeScreen) {
    if (xp >= 100) {
        levelUp();
    } else if (hp <= 0) {
        setAlive(false);
        changeScreen();
    }
}

void Player::addWeapon(Weapon *weapon) {
    weapons.push_back(weapon);
}

void Player::addArmor(Armor *armor) {
    armors.push_back(armor);
}

void Player::addPotion(Potion *potion) {
    potions.push_back(potion);
}

void Player::addDamage(const int damage) {
    this->damage += damage;
}

void Player::addHp(const int hp) {
    this->hp += hp;
}

void Player::addMaxHp(const int maxHp) {
    this->maxHp += maxHp;
}

void Player::usePotion() {
    if (hp != maxHp) {
        if (!potions.empty()) {
            if (hp + potions.at(0)->getHpGain() >= maxHp) {
                hp = maxHp;
            } else {
                hp += potions.at(0)->getHpGain();
            }
            potions.erase(potions.begin() + potions.size() - 1);
        }
    }
}

int Player::getTotalDamage() const {
    int damage = this->damage;
    for (const Weapon *weapon: weapons) {
        damage += weapon->getDamage();
    }
    return damage;
}

bool Player::weaponOwned(const Weapon *weapon) const {
    for (const Weapon *search: weapons) {
        if (search->getId() == weapon->getId()) {
            return true; //Owned
        }
    }
    return false; //Not owned
}

bool Player::armorOwned(const Armor *armor) const {
    for (const Armor *search: armors) {
        if (search->getId() == armor->getId()) {
            return true; //Owned
        }
    }
    return false; //Not owned
}

int Player::getTotalDefense() const {
    int defense = armor;
    for (const Armor *armor: armors) {
        defense += armor->getArmor();
    }
    return defense;
}

int Player::getXp() const {
    return xp;
}

int Player::getMaxHp() const {
    return maxHp;
}

int Player::getLevel() const {
    return level;
}

int Player::getDamage() const {
    return damage;
}

Role Player::getRole() const {
    return role;
}

void Player::addXp(const int xp) {
    this->xp += xp;
}

void Player::addCoins(const int coins) {
    this->coins += coins;
}

void Player::removeCoins(const int coins) {
    this->coins -= coins;
}

int Player::getCoins() const {
    return coins;
}

int Player::getRange() const {
    return range;
}

int Player::getNumberOfPotions() const {
    return potions.size();
}
