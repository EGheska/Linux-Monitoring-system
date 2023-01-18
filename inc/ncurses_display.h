#ifndef NCURSES_DISPLAY_H
#define NCURSES_DISPLAY_H
#include <curses.h>

#include "system.h"

namespace NCursesDisplay {
void Display(System& system);
void DisplaySystem(System& system, WINDOW* window);
std::string ProgressBar(float percent);
};
#endif