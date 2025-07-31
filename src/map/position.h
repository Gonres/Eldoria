//
// Created by Lukyn on 27.11.2024.
//

#ifndef POSITION_H
#define POSITION_H
#include <cmath>

struct Position {
    unsigned int x;
    unsigned int y;

    static unsigned int getDistanceX(const unsigned int playerPositionX, const unsigned int otherPositionX) {
        return abs(static_cast<int>(playerPositionX - otherPositionX));
    }

    static unsigned int getDistanceY(const unsigned int playerPositionY, const unsigned int otherPositionY) {
        return abs(static_cast<int>(playerPositionY - otherPositionY));
    }

    // Check if player is in range 1 of another object.
    static bool isInRangeOfOne(const unsigned int playerPositionX, const unsigned int playerPositionY,
                               const unsigned int otherPositionX, const unsigned int otherPositionY) {
        return getDistanceX(playerPositionX, otherPositionX) <= 1 && getDistanceY(playerPositionY, otherPositionY) <= 1;
    }
};

#endif //POSITION_H
