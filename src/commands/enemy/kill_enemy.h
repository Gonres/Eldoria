#ifndef KILL_ENEMY_H
#define KILL_ENEMY_H
#include "../command.h"
#include "../../domain/entities/enemy.h"

class KillEnemy final : public Command {
public:
    KillEnemy(Enemy *enemy, Map *map);

private:
    Enemy *enemy;
    Map *map;

    void execute() override;
};

#endif //KILL_ENEMY_H
