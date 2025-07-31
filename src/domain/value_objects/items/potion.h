//
// Created by Lukyn on 26.12.2024.
//

#ifndef POTION_H
#define POTION_H

class Potion {
public:
    Potion();

    int getHpGain() const;

    int getPrice() const;

private:
    int m_hpGain;
    int m_price;
};

#endif //POTION_H
