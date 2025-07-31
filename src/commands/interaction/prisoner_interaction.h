//
// Created by Lukyn on 16.01.2025.
//

#ifndef PRISONER_INTERACTION_H
#define PRISONER_INTERACTION_H

#include "../command.h"
#include "../../domain/entities/player.h"
#include "../../domain/value_objects/prisoner.h"
#include "../../map/map.h"

class PrisonerInteraction final : public Command {
public:
    PrisonerInteraction(Prisoner *prisoner, Map *map, Player *player);

    void execute() override;

private:
    Prisoner *prisoner;
    Map *map;
    Player *player;
};

#endif //PRISONER_INTERACTION_H
