//
// Created by Lukyn on 14.12.2024.
//

#include "merchant.h"

Merchant::Merchant(const Position position): position(position) {
}

Position Merchant::getPosition() const {
    return position;
}

bool Merchant::isAnyMerchantInRange(const Position playerPosition) const {
    bool isMerchantInRange = false;
    if (Position::isInRangeOfOne(playerPosition.x, playerPosition.y,
                                 position.x, position.y)) {
        isMerchantInRange = true;
    }
    return isMerchantInRange;
}
