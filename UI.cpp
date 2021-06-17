/*
 * @file UI.cpp
 * @author 김명환(20181582), 임태민(20171690)
 * @brief 
 * @version 1.0
 * @date 2021-05-23
 */

#include "UI.h"
#include <unistd.h>
#include <locale.h>
#include <string>

UI::UI()
{
    startScreen();
}

UI::~UI()
{
    endwin();
}

void UI::startScreen()
{
	initscr();                          
	noecho();                           
	setlocale(LC_ALL, "ko_KR.utf8");
	resize_term(40, 80); 
	mvprintw(1, 30, "   Snake   Game    ");
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_WHITE);
	attron(COLOR_PAIR(1));
	border(ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
	attroff(COLOR_PAIR(1));
	refresh();

	WINDOW* maker = newwin(7, 20, 1, 58);
	wborder(maker, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
	mvprintw(1, 65.5, "Maker");
	mvprintw(2, 59, "Kim Myeonghwan");
	mvprintw(3, 59, "(20181582)");
	mvprintw(5, 59, "Lim Taemin");
	mvprintw(6, 59, "(20171690)");
	wrefresh(maker);

	WINDOW* startMenu = newwin(10, 45, 29, 16.5);
	keypad(startMenu, TRUE);
	wborder(startMenu, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);

    mvprintw(34, 25.5, "Press any key to start...");
    wrefresh(startMenu);
    if(getch())
    {
        /* Game Start */
        eraseScreen(startMenu);
        eraseScreen(maker);
        UI::gameScreen();
    }
}


void UI::gameScreen()
{
	WINDOW* gameScreen = newwin(1,1,1,1);
    keypad(gameScreen, TRUE);
}

void UI::eraseScreen(WINDOW* window)
{
	keypad(window, FALSE);
	werase(window);
	wrefresh(window);
	delwin(window);
}
