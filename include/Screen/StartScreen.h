/**
 * @file StartScreen.h
 * @author 김명환(20181582)
 * @brief 처음 시작했을 때, 등장하는 Screen
 * @version 1.0
 * @date 2021-05-27
 * 
 */

#ifndef STARTSCREEN_H
#define STARTSCRREN_H

#include "IScreen.h"
#include <ncurses.h>


class StartScreen : protected IScreen
{
    public:
        StartScreen();
        ~StartScreen();
        void initScreen();
        void startMenu();
        void maker();
        void eraseScreen(WINDOW* window);
};

#endif