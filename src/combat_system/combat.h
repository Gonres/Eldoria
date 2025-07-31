#ifndef COMBAT_H
#define COMBAT_H
#include <memory>

#include "combat_state.h"
#include "../domain/entities/enemy.h"
#include "../domain/entities/player.h"

class Combat {
public:
    Combat(Enemy *enemy, Player *player);

    void damageEnemy() const;

    void damagePlayer() const;

    void handleCombat();

    bool isPlayerInRange() const;

private:
    std::unique_ptr<CombatState> combatState;
    Enemy *enemy;
    Player *player;
    inline static bool startedCombat = false;
    int randomDamage;

    void setState(std::unique_ptr<CombatState>);

    void update();

    void startCombat();

    void endCombat();

    void displayCombatHeader();

    void handleCombatAttack() const;
};

#endif //COMBAT_H
