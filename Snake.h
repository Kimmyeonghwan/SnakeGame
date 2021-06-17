/**
 * @file Snake.h
 * @author 김명환(20181582), 임태민(20171690)
 * @brief 
 * @version 1.0
 * @date 2021-06-01
 * 
 * @copyright Copyright (c) 2021
 */
#include <iostream>
#include <stdlib.h>
#include <list>
#include <vector>
using namespace std;

class Snake {
private:
	int x;
	int y;
public:
	Snake(int a, int b){
	x = a;
	y = b;
}
	int getX(){return x;}
	int getY(){return y;}
};
