/**
 * @file Direction.h
 * @author 배용하(20191602)
 * @brief 
 * @version 1.0
 * @date 2021-05-28
 * 
 */

#ifndef DIRECTION_H
#define DIRECTION_H

#include <ncurses.h>

class Direction
{
    private:
        int key;
    public:
        Direction() : key(0) {}
        Direction(int k);
        ~Direction();
    static Direction UP, DOWN, LEFT, RIGHT;
};

Direction Direction::UP = Direction(KEY_UP);
Direction Direction::DOWN = Direction(KEY_DOWN);
Direction Direction::LEFT = Direction(KEY_LEFT);
Direction Direction::RIGHT = Direction(KEY_RIGHT);

#endif