#include "merchant_interaction.h"

#include "../../tools/keyboard_key.h"

MerchantInteraction::MerchantInteraction(Merchant *merchant, const std::function<void()> &changeScreen,
                                         Player *player) {
    this->merchant = merchant;
    this->changeScreen = changeScreen;
    this->player = player;
}

void MerchantInteraction::execute() {
    if (merchant == nullptr) {
        return;
    }
    // Check if player is in range of 1 of merchant.
    if (merchant->isAnyMerchantInRange(player->getPosition()) &&
        isKeyDown(KEY_E)) {
        changeScreen();
    }
}
