//
// Created by vitab on 10.12.2024.
//

#ifndef GLOBAL_SETTINGS_H
#define GLOBAL_SETTINGS_H
#include <ctime>
#include <windows.h>

class GlobalSettings {
public:
    GlobalSettings();

    static int getRandomNumber(int maxNumber);

    static BOOL setFontSize();

    static void hideCursor();

    static void clearConsoleOnNewScreen();

    static void clearScreen();

    static void turnOnSupportForANSI();

private:
    static bool supportsANSI();
};

#endif //GLOBAL_SETTINGS_H
