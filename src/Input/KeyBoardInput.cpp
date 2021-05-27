/**
 * @file KeyBoardInput.cpp
 * @author 배용하 (20191602), 김명환 (20181582)
 * @version 1.0
 * @date 2021-05-28
 * 
 */
#include <ncurses.h>
#include "Input/KeyBoardInput.h"

const char* KeyBoardInput::getInput()
{

    keypad(stdscr, TRUE);
    int key = wgetch(stdscr);
    return keyname(key);
}