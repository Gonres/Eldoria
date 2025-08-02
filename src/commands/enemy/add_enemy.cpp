#include "add_enemy.h"

#include "../../domain/entities/basilisk.h"
#include "../../domain/entities/gargoyle.h"
#include "../../domain/entities/ghoul.h"
#include "../../domain/entities/mummy.h"
#include "../../domain/entities/necromancer.h"

AddEnemy::AddEnemy(
    Map *map,
    const EnemyType type,
    const Position position
) : position(position) {
    this->map = map;
    this->type = type;
}

void AddEnemy::clearEnemies() {
    enemies.clear();
}

std::vector<Enemy *> AddEnemy::getEnemies() {
    return enemies;
}

void AddEnemy::execute() {
    std::unordered_map<EnemyType, Enemy *> enemiesToAdd = {
        {EnemyType::mummy, new Mummy(position)},
        {EnemyType::ghoul, new Ghoul(position)},
        {EnemyType::gargoyle, new Gargoyle(position)},
        {EnemyType::basilisk, new Basilisk(position)},
        {EnemyType::necromancer, new Necromancer(position)},
    };
    auto it = enemiesToAdd.find(type);
    if (it != enemiesToAdd.end()) {
        enemies.emplace_back(it->second);
        map->putCharacterInPosition(it->second->getPosition(), '!');
    }
}
