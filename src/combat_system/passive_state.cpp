#include "passive_state.h"

#include "combat.h"
#include "../tools/keyboard_key.h"

bool PassiveState::isAggroed() {
    return false;
}

void PassiveState::handleCombat(const Combat &combat) {
    if (combat.isPlayerInRange() && isKeyDown(KEY_F)) {
        combat.damageEnemy();
    }
}
