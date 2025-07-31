#ifndef LEVELS_H
#define LEVELS_H

#include <vector>
#include "map.h"
#include "../commands/enemy/add_enemy.h"
#include "../commands/npc/add_merchant.h"
#include "../commands/npc/add_prisoner.h"
#include "../domain/entities/player.h"

class Levels {
public:
    Levels();

    ~Levels();

    void loadAllLevels() const;

    void renderCurrentLevel() const;

    void nextLevel(Player *player, const std::function<void()> &changeScreen);

    Map *getMap() const;

    std::vector<Map *> getMaps() const;

    int getCurrentLevel() const;

    AddMerchant *getMerchant() const;

    static bool isAnyPrisonerInRange(const Player *player);

    static bool isAnyEnemyInRange(const Player *player);

private:
    int currentLevel;
    std::vector<Map *> maps;
    AddMerchant *addMerchant;

    void clearCharactersFromPreviousLevel() const;

    void level0() const;

    void level1() const;

    void level2() const;

    void level3() const;

    void level4() const;

    void level5() const;

    void level6() const;

    void level7() const;

    void level8() const;

    void level9() const;

    void level10() const;

    void level11() const;

    void level12() const;

    void level13() const;

    void level14() const;

    void level15() const;

    void level16() const;

    void level17() const;

    void level18() const;

    void level19() const;
};

#endif //LEVELS_H
