#include "levels.h"

#include <algorithm>
#include <functional>
#include <unordered_map>

#include "../tools/global_settings.h"

Levels::Levels() {
    this->currentLevel = 0;
    maps.reserve(20); // Reserve memory for the number of caves.
    maps.emplace_back(new Map(8, 10, DoorPosition::bottomDoor)); //level 0
    maps.emplace_back(new Map(10, 15, DoorPosition::leftDoor)); //level 1
    maps.emplace_back(new Map(10, 15, DoorPosition::bottomDoor)); //level 2
    maps.emplace_back(new Map(15, 25, DoorPosition::rightDoor)); //level 3
    maps.emplace_back(new Map(8, 10, DoorPosition::bottomDoor)); //level 4
    maps.emplace_back(new Map(15, 18, DoorPosition::leftDoor)); //level 5
    maps.emplace_back(new Map(11, 30, DoorPosition::bottomDoor)); //level 6
    maps.emplace_back(new Map(12, 33, DoorPosition::bottomDoor)); //level 7
    maps.emplace_back(new Map(14, 28, DoorPosition::rightDoor)); //level 8
    maps.emplace_back(new Map(8, 10, DoorPosition::bottomDoor)); //level 9
    maps.emplace_back(new Map(11, 30, DoorPosition::leftDoor)); //level 10
    maps.emplace_back(new Map(14, 28, DoorPosition::bottomDoor)); //level 11
    maps.emplace_back(new Map(12, 33, DoorPosition::rightDoor)); //level 12
    maps.emplace_back(new Map(11, 30, DoorPosition::rightDoor)); //level 13
    maps.emplace_back(new Map(8, 10, DoorPosition::bottomDoor)); //level 14
    maps.emplace_back(new Map(14, 28, DoorPosition::bottomDoor)); //level 15
    maps.emplace_back(new Map(12, 33, DoorPosition::rightDoor)); //level 16
    maps.emplace_back(new Map(11, 30, DoorPosition::rightDoor)); //level 17
    maps.emplace_back(new Map(8, 10, DoorPosition::bottomDoor)); //level 18
    maps.emplace_back(new Map(15, 30, DoorPosition::leftDoor)); //level 19
    maps[0]->putCharacterInPosition(Position{5, 1}, '@');
}

Levels::~Levels() {
    for (const Map *map: maps) {
        delete map;
    }
}

void Levels::loadAllLevels() const {
    static std::vector levelsLoaded(maps.size(), false);
    if (currentLevel < maps.size() && !levelsLoaded[currentLevel]) {
        std::unordered_map<int, std::function<void()> > levels = {
            {0, [this] { level0(); }},
            {1, [this] { level1(); }},
            {2, [this] { level2(); }},
            {3, [this] { level3(); }},
            {4, [this] { level4(); }},
            {5, [this] { level5(); }},
            {6, [this] { level6(); }},
            {7, [this] { level7(); }},
            {8, [this] { level8(); }},
            {9, [this] { level9(); }},
            {10, [this] { level10(); }},
            {11, [this] { level11(); }},
            {12, [this] { level12(); }},
            {13, [this] { level13(); }},
            {14, [this] { level14(); }},
            {15, [this] { level15(); }},
            {16, [this] { level16(); }},
            {17, [this] { level17(); }},
            {18, [this] { level18(); }},
            {19, [this] { level19(); }}
        };
        auto it = levels.find(currentLevel);
        if (it != levels.end()) {
            it->second();
            levelsLoaded[currentLevel] = true;
        }
    }
}

void Levels::renderCurrentLevel() const {
    if (currentLevel >= 0 && currentLevel < maps.size()) {
        maps[currentLevel]->printMap();
    }
}

void Levels::nextLevel(Player *player, const std::function<void()> &changeScreen) {
    if (currentLevel + 1 < maps.size()) {
        clearCharactersFromPreviousLevel();
        GlobalSettings::clearConsoleOnNewScreen();
        const DoorPosition lastDoorPosition = maps[currentLevel]->getDoorPosition();
        // Advance to the next level
        ++currentLevel;
        player->addXp(10);

        const Position newPlayerPosition = maps[currentLevel]->getStartingPosition(lastDoorPosition);
        // Put player on the side which he walked from
        player->setPosition(newPlayerPosition);
        maps[currentLevel]->putCharacterInPosition(newPlayerPosition, '@');
    } else {
        changeScreen();
    }
}

Map *Levels::getMap() const {
    return maps[currentLevel];
}

std::vector<Map *> Levels::getMaps() const {
    return maps;
}

int Levels::getCurrentLevel() const {
    return currentLevel;
}

void Levels::clearCharactersFromPreviousLevel() const {
    for (const Enemy *enemy: AddEnemy::getEnemies()) {
        maps[currentLevel]->clearCharacterFromPosition(enemy->getPosition());
    }
    AddEnemy::clearEnemies();
    Merchant *merchant = AddMerchant::getMerchant();
    if (merchant != nullptr) {
        maps[currentLevel]->clearCharacterFromPosition(merchant->getPosition());
        AddMerchant::setMerchantToNull();
    }
    delete merchant;
    for (const Prisoner *prisoner: AddPrisoner::getPrisoners()) {
        maps[currentLevel]->clearCharacterFromPosition(prisoner->getPosition());
    }
    AddPrisoner::clearPrisoners();
}

void Levels::level0() const {
    Command::execute(AddEnemy(maps[currentLevel], EnemyType::mummy, Position{2, 4}));
    Command::execute(AddPrisoner(maps[currentLevel], Position{3, 3}));
}

void Levels::level1() const {
    Command::execute(AddEnemy(maps[currentLevel], EnemyType::mummy, Position{2, 4}));
    Command::execute(AddEnemy(maps[currentLevel], EnemyType::mummy, Position{5, 6}));
    Command::execute(AddPrisoner(maps[currentLevel], Position{7, 6}));
}

void Levels::level2() const {
    Command::execute(AddEnemy(maps[currentLevel], EnemyType::mummy, Position{4, 4}));
    Command::execute(AddEnemy(maps[currentLevel], EnemyType::mummy, Position{7, 6}));
    Command::execute(AddPrisoner(maps[currentLevel], Position{8, 3}));
    Command::execute(AddPrisoner(maps[currentLevel], Position{5, 4}));
}

void Levels::level3() const {
    Command::execute(AddEnemy(maps[currentLevel], EnemyType::mummy, Position{10, 4}));
    Command::execute(AddEnemy(maps[currentLevel], EnemyType::mummy, Position{13, 8}));
    Command::execute(AddEnemy(maps[currentLevel], EnemyType::ghoul, Position{5, 8}));
    Command::execute(AddPrisoner(maps[currentLevel], Position{4, 6}));
    Command::execute(AddPrisoner(maps[currentLevel], Position{12, 7}));
}

void Levels::level4() const {
    Command::execute(AddMerchant(maps[currentLevel], Position{6, 3}));
}

void Levels::level5() const {
    Command::execute(AddEnemy(maps[currentLevel], EnemyType::ghoul, Position{4, 12}));
    Command::execute(AddEnemy(maps[currentLevel], EnemyType::ghoul, Position{6, 8}));
    Command::execute(AddPrisoner(maps[currentLevel], Position{12, 9}));
}

void Levels::level6() const {
    Command::execute(AddEnemy(maps[currentLevel], EnemyType::ghoul, Position{15, 8}));
    Command::execute(AddEnemy(maps[currentLevel], EnemyType::ghoul, Position{10, 6}));
    Command::execute(AddPrisoner(maps[currentLevel], Position{12, 9}));
}

void Levels::level7() const {
    Command::execute(AddEnemy(maps[currentLevel], EnemyType::gargoyle, Position{15, 8}));
    Command::execute(AddEnemy(maps[currentLevel], EnemyType::gargoyle, Position{10, 3}));
    Command::execute(AddPrisoner(maps[currentLevel], Position{25, 2}));
}

void Levels::level8() const {
    Command::execute(AddEnemy(maps[currentLevel], EnemyType::gargoyle, Position{8, 4}));
    Command::execute(AddEnemy(maps[currentLevel], EnemyType::ghoul, Position{4, 11}));
    Command::execute(AddEnemy(maps[currentLevel], EnemyType::mummy, Position{17, 2}));
    Command::execute(AddPrisoner(maps[currentLevel], Position{19, 6}));
    Command::execute(AddPrisoner(maps[currentLevel], Position{25, 3}));
}

void Levels::level9() const {
    Command::execute(AddMerchant(maps[currentLevel], Position{6, 3}));
}

void Levels::level10() const {
    Command::execute(AddEnemy(maps[currentLevel], EnemyType::gargoyle, Position{15, 8}));
    Command::execute(AddEnemy(maps[currentLevel], EnemyType::gargoyle, Position{10, 6}));
    Command::execute(AddPrisoner(maps[currentLevel], Position{12, 9}));
    Command::execute(AddPrisoner(maps[currentLevel], Position{14, 10}));
}

void Levels::level11() const {
    Command::execute(AddEnemy(maps[currentLevel], EnemyType::gargoyle, Position{8, 4}));
    Command::execute(AddEnemy(maps[currentLevel], EnemyType::ghoul, Position{4, 11}));
    Command::execute(AddEnemy(maps[currentLevel], EnemyType::mummy, Position{17, 2}));
    Command::execute(AddPrisoner(maps[currentLevel], Position{19, 6}));
    Command::execute(AddPrisoner(maps[currentLevel], Position{25, 3}));
}

void Levels::level12() const {
    Command::execute(AddEnemy(maps[currentLevel], EnemyType::gargoyle, Position{15, 8}));
    Command::execute(AddEnemy(maps[currentLevel], EnemyType::gargoyle, Position{10, 3}));
    Command::execute(AddPrisoner(maps[currentLevel], Position{25, 2}));
    Command::execute(AddPrisoner(maps[currentLevel], Position{21, 4}));
}

void Levels::level13() const {
    Command::execute(AddEnemy(maps[currentLevel], EnemyType::basilisk, Position{15, 8}));
    Command::execute(AddEnemy(maps[currentLevel], EnemyType::ghoul, Position{10, 6}));
    Command::execute(AddPrisoner(maps[currentLevel], Position{12, 9}));
}

void Levels::level14() const {
    Command::execute(AddMerchant(maps[currentLevel], Position{6, 3}));
}

void Levels::level15() const {
    Command::execute(AddEnemy(maps[currentLevel], EnemyType::gargoyle, Position{8, 4}));
    Command::execute(AddEnemy(maps[currentLevel], EnemyType::ghoul, Position{4, 11}));
    Command::execute(AddEnemy(maps[currentLevel], EnemyType::basilisk, Position{17, 2}));
    Command::execute(AddPrisoner(maps[currentLevel], Position{19, 6}));
    Command::execute(AddPrisoner(maps[currentLevel], Position{25, 3}));
}

void Levels::level16() const {
    Command::execute(AddEnemy(maps[currentLevel], EnemyType::gargoyle, Position{15, 8}));
    Command::execute(AddEnemy(maps[currentLevel], EnemyType::basilisk, Position{10, 3}));
    Command::execute(AddPrisoner(maps[currentLevel], Position{25, 2}));
    Command::execute(AddPrisoner(maps[currentLevel], Position{18, 5}));
}

void Levels::level17() const {
    Command::execute(AddEnemy(maps[currentLevel], EnemyType::basilisk, Position{15, 8}));
    Command::execute(AddEnemy(maps[currentLevel], EnemyType::ghoul, Position{10, 6}));
    Command::execute(AddPrisoner(maps[currentLevel], Position{12, 9}));
    Command::execute(AddPrisoner(maps[currentLevel], Position{9, 5}));
}

void Levels::level18() const {
    Command::execute(AddMerchant(maps[currentLevel], Position{6, 3}));
}

void Levels::level19() const {
    Command::execute(AddEnemy(maps[currentLevel], EnemyType::necromancer, Position{4, 5}));
}

bool Levels::isAnyPrisonerInRange(const Player *player) {
    return std::ranges::any_of(
        AddPrisoner::getPrisoners(),
        [player](const Prisoner *prisoner) {
            return Position::isInRangeOfOne(
                player->getPosition().x,
                player->getPosition().y,
                prisoner->getPosition().x,
                prisoner->getPosition().y);
        });
}

bool Levels::isAnyEnemyInRange(const Player *player) {
    return std::ranges::any_of(
        AddEnemy::getEnemies(),
        [player](const Enemy *enemy) {
            return player->isInRange(player->getPosition(), enemy->getPosition());
        });
}
