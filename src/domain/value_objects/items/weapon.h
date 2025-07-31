//
// Created by Lukyn on 26.12.2024.
//

#ifndef WEAPON_H
#define WEAPON_H

class Weapon {
public:
    Weapon(int damage, int price);

    int getDamage() const;

    int getPrice() const;

    int getId() const;

private:
    int m_damage;
    int m_price;
    int m_id;
    static int s_counter;
};

#endif //WEAPON_H
