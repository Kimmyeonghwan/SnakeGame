/**
 * @file StartScreen.cpp
 * @author 김명환(20181582)
 * @version 1.0
 * @date 2021-05-27
 * 
 */

#include "Screen/StartScreen.h"
#include <unistd.h>
#include <locale.h>
#include <string>

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
    setlocale(LC_ALL, "ko_KR.utf8");
    resize_term(22, 67); // FileInput에서 width, height를 불러와서 설정하는 것은 어떨까? 이건 StageScreen에서 적용?
	mvprintw(2, 23, "   Snake   Game    ");
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
	mvprintw(2, 47, "Kim Myeonghwan");
	mvprintw(3, 47, "(20181582)");
    mvprintw(5, 47, "Lim Taemin");
    mvprintw(6, 47, "(20171609)");
	wrefresh(maker);
}

void StartScreen::startMenu()
{
    WINDOW* startMenu = newwin(10, 45, 10, 10);
    keypad(startMenu, TRUE);
    wborder(startMenu, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);

	
	mvprintw(15, 19, "Press any key to start...");
	wrefresh(startMenu);
    if(getch())
    {
        /* Game Start */
        keypad(startMenu, FALSE);
        eraseScreen(startMenu);
        //eraseScreen(maker);
    }
}

void StartScreen::eraseScreen(WINDOW* window)
{
    werase(window);
    wrefresh(window);
    delwin(window);
}
