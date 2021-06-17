/*
 * @file Map.h
 * @author 김명환(20181582), 임태민(20171690)
 * @brief 
 * @version 1.0
 * @date 2021-05-23
 */

#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>
#include "Object.h"

using namespace std;

class Map
{
    private:
        int width, height;

    public:
        //int width, height;
        int level;
        //vector<vector<Object> > map;
        Map(int level = 1); // FileInput Constructor
        ~Map();
        string getPath() const;
        void readFile(); // path에 있는 맵파일을 objects로 바꾸는 과정
        Map convertGameMap(); // objects를 GameMap으로 바꾸는 과정
        bool isFileExist(); // 파일이 존재하는지 확인

        vector<vector<Object> > map;
        Map(vector<vector<Object> > map);
        void setObject(int x, int y, Object o);
};

#endif