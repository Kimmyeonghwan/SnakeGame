/**
 * @file StartScreen.cpp
 * @author 배용하(20191602)
 * @version 1.0
 * @date 2021-05-27
 * 
 */

#include "Screen/StartScreen.h"
#include <ncurses.h>

StartScreen::StartScreen()
{
    initScreen();
    maker();
    startMenu();
}

StartScreen::~StartScreen()
{
    endwin();
}

void StartScreen::initScreen()
{
    initscr();                          // init screen
    noecho();                           // input이 screen에 보이지 않음.
    //setlocale(LC_ALL, "");
    resize_term(22, 67);
	mvprintw(2, 26, "  Snake  Game  ");
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_WHITE);
    attron(COLOR_PAIR(1));
    border(ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
    attroff(COLOR_PAIR(1));
    refresh();
}

void StartScreen::maker()
{
	WINDOW* maker = newwin(9, 20, 1, 45);
    keypad(maker, TRUE);
    wborder(maker, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
	mvprintw(1, 53, "Maker");
	mvprintw(2, 47, "qodydgk()");
	mvprintw(3, 47, "dlaxoals()");
	mvprintw(4, 47, "rlaaudghks(20181582)");
	wrefresh(maker);
}

void StartScreen::startMenu()
{
    WINDOW* window_start = newwin(10, 45, 10, 10);
    keypad(window_start, TRUE);
    wborder(window_start, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);

	
	mvprintw(15, 19, "Press any key to start...");
	wrefresh(window_start);
	while(1)
	{
		if(getch()) break;

	}
	endwin();
}