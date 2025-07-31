#ifndef PASSIVE_STATE_H
#define PASSIVE_STATE_H
#include "combat_state.h"

class PassiveState final : public CombatState {
public:
    bool isAggroed() override;

    void handleCombat(const Combat &combat) override;
};

#endif //PASSIVE_STATE_H
