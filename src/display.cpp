#include <curses.h>
#include <chrono>
#include <string>
#include <thread>
#include <vector>



#include "system.h"
#include "format.h"
#include "display.h"


// 50 bars uniformly displayed from 0 - 100 %
// 2% is one bar(|)
std::string NCursesDisplay::ProgressBar(float percent) {
  std::string result{""};
  int size{50};
  float bars{percent * size};

  for (int i{0}; i < size; ++i) {
    result += i <= bars ? '|' : ' ';
  }

  std::string display{std::to_string(percent * 100).substr(0, 4)};
  if (percent < 0.1 || percent == 1.0)
    display = "" + std::to_string(percent * 100).substr(0, 3);
  return result + "" + display + "/100%";
}

void NCursesDisplay::DisplaySystem(System& system, WINDOW* window) {
  int row{0};
  mvwaddstr(window, ++row, 2, ("OS: " + system.OperatingSystem()).c_str());
  mvwaddstr(window, ++row, 2, ("Kernel: " + system.Kernel()).c_str());
  mvwaddstr(window, ++row, 2, "CPU:");
  wattron(window, COLOR_PAIR(1));
  mvwaddstr(window, row, 9, " ");
  waddstr(window, ProgressBar(system.Cpu().Utilization()).c_str());
  wattroff(window, COLOR_PAIR(1));
  mvwaddstr(window, ++row, 2, "Memory:  ");
  wattron(window, COLOR_PAIR(1));
  mvwaddstr(window, row, 10, "");
  waddstr(window, ProgressBar(system.MemoryUtilization()).c_str());
  wattroff(window, COLOR_PAIR(1));
  mvwaddstr(window, ++row, 2,
            ("Total Processes: " + std::to_string(system.TotalProcesses())).c_str());
  mvwaddstr(
      window, ++row, 2,
      ("Running Processes: " + std::to_string(system.RunningProcesses())).c_str());
  mvwaddstr(window, ++row, 2,
            ("Up Time: " + Format::ElapsedTime(system.UpTime())).c_str());
  wrefresh(window);
}

void NCursesDisplay::Display(System& system) {
  initscr();      // start ncurses
  noecho();       // do not print input values
  cbreak();       // terminate ncurses on ctrl + c
  start_color();  // enable color

  int x_max{getmaxx(stdscr)};
  WINDOW* system_window = newwin(9, x_max - 1, 0, 0);

  while (1) {
    init_pair(1, COLOR_BLUE, COLOR_BLACK);

    box(system_window, 0, 0);

    DisplaySystem(system, system_window);

    wrefresh(system_window);

    refresh();
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  endwin();
}