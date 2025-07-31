#ifndef ENEMY_MOVEMENT_H
#define ENEMY_MOVEMENT_H

#include "../domain/entities/enemy.h"
#include "../domain/entities/player.h"
#include "../map/position.h"

class EnemyMovement {
public:
    explicit EnemyMovement(Enemy *enemy);

    void moveEnemy(Map *map, const Player *player) const;

private:
    Enemy *enemy;

    Position calculateNextPosition(const Player *player) const;

    void updatePosition(Map *map, Position nextPosition) const;
};

#endif //ENEMY_MOVEMENT_H
