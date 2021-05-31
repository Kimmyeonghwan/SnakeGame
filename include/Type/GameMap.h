/**
 * @file Map.h
 * @author 배용하(20191602)
 * @brief 
 * @version 1.0
 * @date 2021-05-28
 * 
 */

#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>
#include "Object.h"

using namespace std;

class GameMap
{
    private:
        int width, height;
    public:
        vector<vector<Object> > map;
        GameMap(vector<vector<Object> > map);
        void setObject(int x, int y, Object o);
};

#endif