/**
 * @file GameScreen.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 1.0
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

  
#ifndef _GAME_FLOW_
#define _GAME_FLOW_

#include <ncurses.h>
#include <string>
#include <vector>
using namespace std;

class GameScreen
{
private :
    vector<int> scores = {0, 0, 0, 0};

public :
    GameScreen();

    void gameEndScreen();
    int stageEnterScreen(const int stage);
    int stageClearScreen(const int stage, const int score);
    void setStageScore(int stage, int score);
    void eraseWindow(WINDOW* window);

};

#endif