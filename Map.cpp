/**
 * @file Map.cpp
 * @author 김명환(20181582), 임태민(20171690)
 * @brief 
 * @version 1.0
 * @date 2021-05-23
 */

#include "Map.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Map::Map(int level) : level(level)
{
    if(!Map::isFileExist()) return;
}

Map::~Map()
{}

string Map::getPath() const {
    return "map/" + to_string(this->level) + ".txt";
}


bool Map::isFileExist()
{
    // 파일이 존재하는지 확인

    ifstream f(getPath(), ios::in);
	if (f.fail())
	{
		cerr << "파일을 열 수 없습니다.\n";
	    return false;
	}
    
    f.close();
    return true;
}

void Map::readFile()
{
    if(!Map::isFileExist()) return;
    ifstream f(getPath());
    string s;

    map.clear();
    height = 0;
    while (f.peek() != EOF) {
        getline(f, s);

        vector<int> map;

        for (char c : s) {
            if (c >= '0' && c <= '9') {
                int obj = c - '0';
                map.push_back(obj);
            }
        }
        this->map.push_back(map);

        ++height;
    }
    width = s.size();

    level++;
}


Map Map::convertGameMap()
{
    return Map(map);
}



Map::Map(vector<vector<int> > map)
{
    height = map.size();
    if (height == 0) {}// error

    width = map[0].size();
    this->map = map;

}

