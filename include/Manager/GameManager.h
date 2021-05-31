/**
 * @file GameManager.h
 * @author 배용하(20191602)
 * @brief Header of GameManager
 * @version 1.0
 * @date 2021-05-28
 * 
 */

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Screen/IScreen.h"

class GameManager
{
    private:
        int elapsedTime = 0;
    public:
        IScreen* scr;
        GameManager();
        ~GameManager();
        void updateGame();

        // create getter, setter method of private member variable `elapsedTime`
        int getElapsedTime();
        void addElapsedTime(int t);

};

#endif