#ifndef ADD_ENEMY_H
#define ADD_ENEMY_H
#include "../command.h"
#include "../../domain/entities/enemy.h"

class AddEnemy final : public Command {
public:
    AddEnemy(Map *map, EnemyType type, Position position);

    static std::vector<Enemy *> getEnemies();

    static void clearEnemies();

private:
    inline static std::vector<Enemy *> enemies = {};
    Map *map;
    EnemyType type;
    Position position;

    void execute() override;
};

#endif //ADD_ENEMY_H
