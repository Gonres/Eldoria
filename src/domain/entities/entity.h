//
// Created by Lukyn on 21.12.2024.
//

#ifndef ENTITY_H
#define ENTITY_H
#include "../../map/position.h"

class Entity {
public:
    Entity(int hp, int damage, int range, bool alive, Position position);

    int getHp() const;

    void takeDamage(int damage);

    bool isAlive() const;

    void setAlive(bool alive);

    Position getPosition() const;

    void setPosition(Position position);

    bool isInRange(Position playerPosition, Position otherPosition) const;

protected:
    int hp;
    int damage;
    int range;
    bool alive;
    Position position;
};

#endif //ENTITY_H
