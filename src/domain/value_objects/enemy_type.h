//
// Created by Lukyn on 14.12.2024.
//

#ifndef ENEMY_TYPE_H
#define ENEMY_TYPE_H

enum class EnemyType { mummy, gargoyle, ghoul, basilisk, necromancer };

inline const char *enemyTypeToString(const EnemyType type) {
    switch (type) {
        case EnemyType::mummy: return "Mummy";
        case EnemyType::gargoyle: return "Gargoyle";
        case EnemyType::ghoul: return "Ghoul";
        case EnemyType::basilisk: return "Basilisk";
        case EnemyType::necromancer: return "Necromancer";
        default: return "Unknown";
    }
}

#endif //ENEMY_TYPE_H
