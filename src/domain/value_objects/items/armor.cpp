//
// Created by Lukyn on 26.12.2024.
//

#include "armor.h"
int Armor::s_counter = 0;

Armor::Armor(const int armor, const int price) {
    m_armor = armor;
    m_price = price;
    s_counter++;
    m_id = s_counter;
}

int Armor::getArmor() const {
    return m_armor;
}

int Armor::getPrice() const {
    return m_price;
}

int Armor::getId() const {
    return m_id;
}
