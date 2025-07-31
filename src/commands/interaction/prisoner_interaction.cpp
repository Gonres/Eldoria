#include "prisoner_interaction.h"

#include "../../tools/keyboard_key.h"

PrisonerInteraction::PrisonerInteraction(Prisoner *prisoner, Map *map, Player *player) {
    this->prisoner = prisoner;
    this->map = map;
    this->player = player;
}

void PrisonerInteraction::execute() {
    // Check if player is in range of 1 of prisoner.
    if (Position::isInRangeOfOne(
            player->getPosition().x,
            player->getPosition().y,
            prisoner->getPosition().x,
            prisoner->getPosition().y
        ) && isKeyDown(KEY_E)) {
        player->addXp(30);
        player->addCoins(200);
        player->addPotion(new Potion);
        map->clearCharacterFromPosition(prisoner->getPosition());
        prisoner->setPosition(Position{9999, 9999});
    }
}

