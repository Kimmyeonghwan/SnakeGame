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
}

StartScreen::~StartScreen()
{
    endwin();
}

void StartScreen::initScreen()
{
    initscr();                          // init screen
    noecho();                           // input이 screen에 보이지 않음.
    keypad(stdscr, true);               // init keypad
}