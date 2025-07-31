//
// Created by Lukyn on 14.12.2024.
//

#include "enemy.h"

#include "../../commands/enemy/kill_enemy.h"
#include "../../tools/global_settings.h"

Enemy::Enemy(const EnemyType enemyType, const int hp, const int damage, const int coinReward, const int xpReward,
             const int potionDropChance, const int range, const Position enemyPosition)
    : Entity(hp, damage, range, true, enemyPosition) {
    this->enemyType = enemyType;
    this->coinReward = coinReward;
    this->xpReward = xpReward;
    this->potionDropChance = potionDropChance;
    this->range = range;
    this->aggroed = false;
}

int Enemy::getDamage() const {
    return damage;
}

int Enemy::getCoinReward() const {
    return coinReward;
}

int Enemy::getXpReward() const {
    return xpReward;
}

EnemyType Enemy::getEnemyType() const {
    return enemyType;
}

int Enemy::getPotionDropChance() const {
    return potionDropChance;
}

bool Enemy::isAggroed() const {
    return aggroed;
}

void Enemy::setAggro(const bool aggroed) {
    this->aggroed = aggroed;
}

void Enemy::checkEnemyHp(Map *map, const std::function<void()> &lootEnemy) {
    if (!alive) {
        return;
    }
    if (hp <= 0) {
        Command::execute(KillEnemy(this, map));
        lootEnemy();
    }
}

int Enemy::randomDamage() const {
    const int max = getDamage() + 2;
    const int min = getDamage() - 2;
    const int range = max - min + 1;
    return rand() % range + min;
}


