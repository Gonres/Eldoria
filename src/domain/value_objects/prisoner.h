//
// Created by Lukyn on 14.12.2024.
//

#ifndef PRISONER_H
#define PRISONER_H
#include "../../map/position.h"

class Prisoner {
public:
    explicit Prisoner(Position position);

    Position getPosition() const;

    void setPosition(Position position);

private:
    Position position;
};

#endif //PRISONER_H
