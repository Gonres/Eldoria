//
// Created by Lukyn on 23.12.2024.
//

#include "basilisk.h"

Basilisk::Basilisk(const Position basiliskPosition)
    : Enemy(EnemyType::basilisk, 50, 45, 400, 90, 50, 5, basiliskPosition) {
}
