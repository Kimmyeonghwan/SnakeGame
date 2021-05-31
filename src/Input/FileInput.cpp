/**
 * @file FileInput.cpp
 * @author 김명환(20181582)
 * @brief 
 * @version 1.0
 * @date 2021-05-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include "Input/FileInput.h"
#include "../Type/GameMap.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

FileInput::FileInput(int level) : level(level)
{
    if(!FileInput::isFileExist()) return;
}

FileInput::~FileInput()
{}

string FileInput::getPath() const {
    return "./map/" + to_string(this->level) + ".txt";
}


bool FileInput::isFileExist()
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

void FileInput::readFile()
{
    if(!FileInput::isFileExist()) return;
    ifstream f(getPath());
    string s;

    map.clear();
    height = 0;
    while (f.peek() != EOF) {
        getline(f, s);

        vector<Object> map;

        for (char c : s) {
            if (c >= '0' && c <= '9') {
                int obj = c - '0';
                map.push_back(Object(obj));
            }
        }
        this->map.push_back(map);

        ++height;
    }
    width = s.size();

    level++;
}

GameMap FileInput::convertGameMap()
{
    return GameMap(map);
}