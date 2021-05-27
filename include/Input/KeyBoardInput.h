/**
 * @file KeyBoardInput.h
 * @author 배용하(20191602), 김명환 (20181582)
 * @brief KeyBoard Input
 * @version 1.0
 * @date 2021-05-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef KEYBOARDINPUT_H
#define KEYBOARDINPUT_H

#include "IInput.h"

class KeyBoardInput : public IInput
{
    public:
        KeyBoardInput();
        ~KeyBoardInput();
        static const char* getInput();
};

#endif