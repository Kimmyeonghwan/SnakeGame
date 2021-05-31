/**
 * @file Map.cpp
 * @author 김명환(20181582)
 * @brief 
 * @version 1.0
 * @date 2021-05-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Type/GameMap.h"
#include <fstream>
using namespace std;

GameMap::GameMap(vector<vector<Object> > map)
{
    height = map.size();
    if (height == 0) {}// error

    width = map[0].size();
    this->map = map;

}

void GameMap::setObject(int x, int y, Object o) {
    if (x < 0 || x >= width) {}// error
    if (y < 0 || y >= height) {}// error

    map[y][x] = o;
}

