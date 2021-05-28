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

FileInput::FileInput(string p)
{
    if(!FileInput::isFileExist()) return;
    ifstream f("../map/" + to_string(this->level) + ".txt", ios::in);
    path = p;
}

FileInput::~FileInput()
{

}

bool FileInput::isFileExist()
{
    // 파일이 존재하는지 확인
    ifstream f("../map/" + to_string(this->level) + ".txt", ios::in);
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
    ifstream f(path);
    string s;
    f >> s;
    

    level++;
}

GameMap FileInput::convertGameMap()
{

}