#include "application.h"

#include <conio.h>

#include "tools/global_settings.h"
#include "tools/keyboard_key.h"

Application::Application() = default;

void Application::run() {
    game = std::make_unique<Game>();
    GlobalSettings::turnOnSupportForANSI();
    GlobalSettings::setFontSize();
    GlobalSettings::hideCursor();
    while (running) {
        GlobalSettings::clearScreen();
        game->render();
        globalKeyId = tolower(_getch()); // Get user input
        game->handleInputs();
    }
}

void Application::shutdown() {
    running = false;
}
