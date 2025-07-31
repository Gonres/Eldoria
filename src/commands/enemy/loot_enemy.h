#ifndef LOOT_ENEMY_H
#define LOOT_ENEMY_H
#include "../command.h"
#include "../../domain/entities/enemy.h"
#include "../../domain/entities/player.h"

class LootEnemy final : public Command {
public:
    LootEnemy(Player *player, Enemy *enemy);

private:
    Player *player;
    Enemy *enemy;

    void execute() override;

    void dropPotion() const;
};

#endif //LOOT_ENEMY_H
