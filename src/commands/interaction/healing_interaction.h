#ifndef HEALING_INTERACTION_H
#define HEALING_INTERACTION_H

#include "../command.h"
#include "../../domain/entities/player.h"

class HealingInteraction final : public Command {
public:
    explicit HealingInteraction(Player *player);

    void execute() override;

private:
    Player *player;
};

#endif //HEALING_INTERACTION_H
