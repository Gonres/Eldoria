//
// Created by Lukyn on 27.12.2024.
//

#include "gargoyle.h"

Gargoyle::Gargoyle(const Position gargoylePosition): Enemy(EnemyType::gargoyle, 50, 35, 300, 75,
                                                           40, 4, gargoylePosition) {
}
