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

void AddEnemy::addMummy(const Position position) {
    Enemy *mummy = new Mummy(position);
    enemies.emplace_back(mummy);
    map->putCharacterInPosition(position, '!');
}

void AddEnemy::addGhoul(const Position position) {
    Enemy *ghoul = new Ghoul(position);
    enemies.emplace_back(ghoul);
    map->putCharacterInPosition(position, '!');
}

void AddEnemy::addGargoyle(const Position position) {
    Enemy *gargoyle = new Gargoyle(position);
    enemies.emplace_back(gargoyle);
    map->putCharacterInPosition(position, '!');
}

void AddEnemy::addBasilisk(const Position position) {
    Enemy *basilisk = new Basilisk(position);
    enemies.emplace_back(basilisk);
    map->putCharacterInPosition(position, '!');
}

void AddEnemy::addNecromancer(const Position position) {
    Enemy *necromancer = new Necromancer(position);
    enemies.emplace_back(necromancer);
    map->putCharacterInPosition(position, '!');
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
