#ifndef GAME_H
#define GAME_H
#include "domain/entities/player.h"
#include "map/levels.h"
#include "ui/menu.h"

class Game {
public:
    Game();

    ~Game();

    void render();

    void handleInputs() const;

private:
    Menu *menu;
    Levels *levels;
    Player *player;

    void displayGUI() const;

    void displayHelp() const;

    void displayPlayerProperties() const;

    Player *initializePlayer();
};

#endif //GAME_H
