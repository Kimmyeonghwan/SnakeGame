/**
 * @file Item.h
 * @author 김명환(20181582), 임태민(20171690)
 * @brief 
 * @version 1.0
 * @date 2021-06-01
 * 
 * @copyright Copyright (c) 2021
 */
#include <iostream>
#include "Wall.h"
#include <vector>
#include "Snake.h"
using namespace std;

class Item{
private:
    int growth1X, growth1Y;
    int growth2X, growth2Y;
    int poisonX, poisonY;
    int gate1X, gate1Y;
    int gate2X, gate2Y;

public:
    Item();
    ~Item();

    int getGrowth1X();
    int getGrowth1Y();
    int getGrowth2X();
    int getGrowth2Y();
    int getPoisonX();
    int getPoisonY();
    int getGate1X();
    int getGate1Y();
    int getGate2X();
    int getGate2Y();

    void createGrowth1(vector<Wall> wall, list<Snake>::iterator it, list<Snake> snakeBody);
    void createGrowth2(vector<Wall> wall, list<Snake>::iterator it, list<Snake> snakeBody);
    void createPoison(vector<Wall> wall, list<Snake>::iterator it, list<Snake> snakeBody);
    void createGate1(vector<Wall> wall, vector<Wall> immuneWall);
    void createGate2(vector<Wall> wall, vector<Wall> immuneWall);
};