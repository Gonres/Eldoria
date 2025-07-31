#include "kill_enemy.h"

KillEnemy::KillEnemy(Enemy *enemy, Map *map) {
    this->enemy = enemy;
    this->map = map;
}

void KillEnemy::execute() {
    enemy->setAggro(false);
    enemy->setAlive(false);
    map->clearCharacterFromPosition(enemy->getPosition());
    enemy->setPosition(Position{9999, 9999});
}
