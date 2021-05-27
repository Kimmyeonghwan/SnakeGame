/**
 * @file FileInput.h
 * @author 배용하(20191602)
 * @brief File Input
 * @version 1.0
 * @date 2021-05-28
 * 
 */

#ifndef FILEINPUT_H
#define FILEINPUT_H

#include <string>
#include "../Type/GameMap.h"

using namespace std;

class FileInput
{
    public:
        int width, height;
        string path;
        char** objects;
        FileInput(string p); // FileInput Constructor
        ~FileInput();
        void readFile(); // path에 있는 맵파일을 objects로 바꾸는 과정

        GameMap convertGameMap(); // objects를 GameMap으로 바꾸는 과정
        bool isFileExist(); // 파일이 존재하는지 확인
};

#endif