#ifndef MERCHANT_INTERACTION_H
#define MERCHANT_INTERACTION_H

#include <functional>

#include "../command.h"
#include "../../domain/entities/player.h"
#include "../../domain/value_objects/merchant.h"

class MerchantInteraction final : public Command {
public:
    MerchantInteraction(Merchant *merchant, const std::function<void()> &changeScreen, Player *player);

    void execute() override;

private:
    Merchant *merchant;
    std::function<void()> changeScreen;
    Player *player;
};

#endif //MERCHANT_INTERACTION_H
