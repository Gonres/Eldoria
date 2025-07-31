//
// Created by Lukyn on 26.12.2024.
//

#include "weapon.h"
int Weapon::s_counter = 0;

Weapon::Weapon(const int damage, const int price) {
    m_damage = damage;
    m_price = price;
    s_counter++;
    m_id = s_counter;
}

int Weapon::getDamage() const {
    return m_damage;
}

int Weapon::getPrice() const {
    return m_price;
}

int Weapon::getId() const {
    return m_id;
}
