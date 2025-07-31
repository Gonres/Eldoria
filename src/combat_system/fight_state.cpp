#include "fight_state.h"

#include "combat.h"
#include "../tools/keyboard_key.h"

bool FightState::isAggroed() {
    return true;
}

void FightState::handleCombat(const Combat &combat) {
    if (isKeyDown(KEY_F)) {
        combat.damageEnemy();
    }
    if (isKeyDown(KEY_F) || movementKeys()) {
        combat.damagePlayer();
    }
}
