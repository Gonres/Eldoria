#ifndef COLOR_H
#define COLOR_H

#include <windows.h>

enum class Colors { red = 04, green = 02, white = 07, selected = 112, yellow = 06 };

inline void setColor(Colors color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, static_cast<WORD>(color));
}

#endif //COLOR_H
