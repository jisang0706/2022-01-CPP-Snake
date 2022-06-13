#ifndef _SETTING_H_
#define _SETTING_H_

#include "GameSettings.h"
#include <ncurses.h>
#include <locale.h>

void NcursesSetting()
{
    setlocale(LC_ALL, "");
    initscr();
    noecho();
    curs_set(0);
    resize_term(MAP_Y + 2, MAP_X * 3 + 4);
    start_color();

    init_pair(1, COLOR_MAGENTA, COLOR_YELLOW);
    attron(COLOR_PAIR(1));
    border(96, 96, 96, 96, 96, 96, 96, 96);
    attroff(COLOR_PAIR(1));

    mvprintw(0, 22, "  2022  Snake  Game  ");
    refresh();
}

#endif
