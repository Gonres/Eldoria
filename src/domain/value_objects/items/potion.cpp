//
// Created by Lukyn on 26.12.2024.
//

#include "potion.h"

Potion::Potion() {
    m_price = 300;
    m_hpGain = 50;
}

int Potion::getPrice() const {
    return m_price;
}

int Potion::getHpGain() const {
    return m_hpGain;
}
