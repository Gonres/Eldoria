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
    if (Position::isInRangeOfOne(playerPosition.x, playerPosition.y,
                                 position.x, position.y)) {
        return true;
    }
    return false;
}
