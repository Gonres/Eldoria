//
// Created by Lukyn on 21.12.2024.
//

#include "entity.h"

Entity::Entity(const int hp, const int damage, const int range, const bool alive, const Position position)
    : position(position) {
    this->hp = hp;
    this->damage = damage;
    this->range = range;
    this->alive = alive;
}

int Entity::getHp() const {
    return hp;
}

void Entity::takeDamage(const int damage) {
    hp -= damage;
}

bool Entity::isAlive() const {
    return alive;
}

void Entity::setAlive(const bool alive) {
    this->alive = alive;
}

Position Entity::getPosition() const {
    return position;
}

void Entity::setPosition(const Position position) {
    this->position = position;
}

bool Entity::isInRange(const Position playerPosition, const Position otherPosition) const {
    if (range >= Position::getDistanceX(playerPosition.x, otherPosition.x)
        && range >= Position::getDistanceY(playerPosition.y, otherPosition.y)) {
        return true;
    }
    return false;
}


