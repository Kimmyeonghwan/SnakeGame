/**
 * @file IInput.h
 * @author 배용하(20191602), 김명환 (20181582)
 * @brief Input Interface
 * @version 1.0
 * @date 2021-05-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef IINPUT_H
#define IINPUT_H


class IInput
{
    public:
        IInput() {}
        virtual ~IInput() {}
        static auto getInput();
};

#endif