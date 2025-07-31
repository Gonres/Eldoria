//
// Created by Lukyn on 27.12.2024.
//

#include "necromancer.h"

Necromancer::Necromancer(const Position necromancerPosition): Enemy(EnemyType::necromancer, 1000, 200, 0, 0, 0, 7,
                                                                    necromancerPosition) {
}
