//
// Created by Lukyn on 14.12.2024.
//

#ifndef ENEMY_H
#define ENEMY_H
#include <functional>

#include "entity.h"
#include "../../map/map.h"
#include "../value_objects/enemy_type.h"

class Enemy : public Entity {
public:
    Enemy(EnemyType enemyType, int hp, int damage, int coinReward, int xpReward, int potionDropChance,
          int range, Position enemyPosition);

    int getDamage() const;

    int getXpReward() const;

    int getCoinReward() const;

    bool isAggroed() const;

    void setAggro(bool aggroed);

    void checkEnemyHp(Map *map, const std::function<void()> &lootEnemy);

    int randomDamage() const;

    EnemyType getEnemyType() const;

    int getPotionDropChance() const;

private:
    EnemyType enemyType;
    int coinReward;
    int xpReward;
    int potionDropChance;
    bool aggroed;
};

#endif //ENEMY_H
