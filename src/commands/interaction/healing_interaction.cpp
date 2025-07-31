#include "healing_interaction.h"

#include "../../tools/keyboard_key.h"

HealingInteraction::HealingInteraction(Player *player) {
    this->player = player;
}

void HealingInteraction::execute() {
    if (isKeyDown(KEY_H)) {
        player->usePotion();
    }
}
