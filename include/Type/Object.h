/**
 * @file Object.h
 * @author 배용하(20191602)
 * @brief 
 * @version 1.0
 * @date 2021-05-28
 * 
 */

#ifndef OBJECT_H
#define OBJECT_H

enum Object {
    AIR = 0,
    WALL = 1,
    IMMUNE_WALL = 2,
    SNAKE_HEAD = 3,
    SNAKE_BODY = 4,
    GATE = 5,
    GROWTH_ITEM = 6,
    POISION_ITEM = 7
};

#endif