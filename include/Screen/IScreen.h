/**
 * @file IScreen.h
 * @author 배용하(20191602)
 * @brief Screen의 Interface
 * @version 1.0
 * @date 2021-05-27
 * 
 */

#ifndef ISCREEN_H
#define ISCRREN_H

class IScreen
{
    public:
        IScreen() {}
        virtual ~IScreen() {}
        virtual void initScreen() = 0;
};

#endif