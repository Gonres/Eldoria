#ifndef APPLICATION_H
#define APPLICATION_H

#include <memory>

#include "game.h"

class Application {
public:
    Application();

    void run();

    static void shutdown();

private:
    inline static bool running = true;
    std::unique_ptr<Game> game;
};

#endif //APPLICATION_H
