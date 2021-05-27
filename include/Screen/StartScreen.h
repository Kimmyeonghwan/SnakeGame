/**
 * @file StartScreen.h
 * @author 배용하(20191602)
 * @brief 처음 시작했을 때, 등장하는 Screen
 * @version 1.0
 * @date 2021-05-27
 * 
 */

#ifndef STARTSCREEN_H
#define STARTSCRREN_H

#include "IScreen.h"

class StartScreen : protected IScreen
{
    public:
        StartScreen();
        ~StartScreen();
        void initScreen();
};

#endif