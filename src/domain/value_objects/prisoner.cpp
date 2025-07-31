//
// Created by Lukyn on 14.12.2024.
//

#include "prisoner.h"

Prisoner::Prisoner(const Position position) : position(position) {
}

Position Prisoner::getPosition() const {
    return position;
}

void Prisoner::setPosition(const Position position) {
    this->position = position;
}
