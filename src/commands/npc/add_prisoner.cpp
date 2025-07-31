//
// Created by Lukyn on 23.12.2024.
//

#include "add_prisoner.h"

AddPrisoner::AddPrisoner(
    Map *map,
    const Position position
) : position(position) {
    this->map = map;
}

std::vector<Prisoner *> AddPrisoner::getPrisoners() {
    return prisoners;
}

void AddPrisoner::clearPrisoners() {
    prisoners.clear();
}

void AddPrisoner::execute() {
    prisoners.emplace_back(new Prisoner(position));
    map->putCharacterInPosition(position, '?');
}
