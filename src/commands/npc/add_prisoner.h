//
// Created by Lukyn on 23.12.2024.
//

#ifndef ADD_PRISONER_H
#define ADD_PRISONER_H
#include <vector>

#include "../command.h"
#include "../../domain/value_objects/prisoner.h"
#include "../../map/map.h"

class AddPrisoner final : public Command {
public:
    AddPrisoner(Map *map, Position position);

    static std::vector<Prisoner *> getPrisoners();

    static void clearPrisoners();

private:
    inline static std::vector<Prisoner *> prisoners = {};
    Map *map;
    Position position;

    void execute() override;
};

#endif //ADD_PRISONER_H
