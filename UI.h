/*
 * @file UI.h
 * @author 김명환(20181582), 임태민(20171690)
 * @brief 
 * @version 1.0
 * @date 2021-05-23
 */

#ifndef UI_H
#define UI_H
#include <ncurses.h>

class UI {
public:
    UI();
    ~UI();
    void startScreen();
    void gameScreen();
    void eraseScreen(WINDOW* window);
};

#endif