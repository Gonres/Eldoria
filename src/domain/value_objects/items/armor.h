//
// Created by Lukyn on 26.12.2024.
//

#ifndef ARMOR_H
#define ARMOR_H

class Armor {
public:
    Armor(int armor, int price);

    int getArmor() const;

    int getPrice() const;

    int getId() const;

private:
    int m_armor;
    int m_price;
    int m_id;
    static int s_counter;
};

#endif //ARMOR_H
