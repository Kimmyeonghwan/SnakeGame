/**
 * @file Item.cpp
 * @author 김명환(20181582), 임태민(20171690)
 * @brief 
 * @version 1.0
 * @date 2021-05-23
 *
 * @date 2021-06-01
 * 
 * @copyright Copyright (c) 2021
 */
#include <iostream>
#include <vector>
#include "Item.h"
#include <stdlib.h>
using namespace std;

Item::Item(){
    /* 변수 초기화 */
    growth1X = -1, growth1Y = -1;
	growth2X = -1, growth2Y = -1;
    poisonX = -1, poisonY = -1;
    gate1X = -1, gate1Y = -1;
    gate2X = -1, gate2Y = -1;
}

Item::~Item(){

}

int Item::getGrowth1X() { return growth1X; }
int Item::getGrowth1Y() { return growth1Y; }
int Item::getGrowth2X() { return growth2X; }
int Item::getGrowth2Y() { return growth2Y; }
int Item::getPoisonX() { return poisonX; }
int Item::getPoisonY() { return poisonY; }
int Item::getGate1X() { return gate1X; }
int Item::getGate1Y() { return gate1Y; }
int Item::getGate2X() { return gate2X; }
int Item::getGate2Y() { return gate2Y; }

void Item::createGrowth1(vector<Wall> wall, list<Snake>::iterator it, list<Snake> snakeBody){
    bool gtset = true;
	while(gtset) {
		growth1X = rand() % 35 + 1;
		growth1Y = rand() % 35 + 1;
		gtset = false;

		for(it = snakeBody.begin(); it != snakeBody.end(); it++) {
			if(growth1X == (*it).getX() && growth1Y == (*it).getY()) {
				gtset = true;
			}
		}
		
		for(int i = 0; i < wall.size(); i++) {
			if(growth1X == wall[i].getX() && growth1Y == wall[i].getY()) {
				gtset = true;
			}
		}
	}
}

void Item::createGrowth2(vector<Wall> wall, list<Snake>::iterator it, list<Snake> snakeBody){
    bool gtset = true;
	while(gtset) {
		growth2X = rand() % 35 + 1;
		growth2Y = rand() % 35 + 1;
		gtset = false;
		for(it = snakeBody.begin(); it != snakeBody.end(); it++) {
			if(growth2X == (*it).getX() && growth2Y == (*it).getY()) {
				gtset = true;
			}
		}
		
		for(int i = 0; i < wall.size(); i++) {
			if(growth2X == wall[i].getX() && growth2Y == wall[i].getY()) {
				gtset = true;
			}
		}
	}
}

void Item::createPoison(vector<Wall> wall, list<Snake>::iterator it, list<Snake> snakeBody){
    bool psset = true;
	while(psset) {
		poisonX = rand() % 35 + 1;
		poisonY = rand() % 35 + 1;
		psset = false;
		
		for(it = snakeBody.begin(); it != snakeBody.end(); it++) {
			if(poisonX == (*it).getX() && poisonY == (*it).getY()) {
				psset = true;
			}
		}
		
		for(int i = 0; i < wall.size(); i++) {
			if(poisonX == wall[i].getX() && poisonY == wall[i].getY()) {
				psset = true;
			}
		}
	}
}

void Item::createGate1(vector<Wall> wall, vector<Wall> immuneWall){
    bool gt1set = true;
	while(gt1set) {
		gate1X = rand() % 35 + 1;
		gate1Y = rand() % 35 + 1;

		for(int i = 0; i < wall.size(); i++) {
			if(gate1X == wall[i].getX() && gate1Y == wall[i].getY()) {
				gt1set = false;
				break;
			} 
		}

		for(int i = 0; i < immuneWall.size(); i++){
			if(gate1X == immuneWall[i].getX() && gate1Y == immuneWall[i].getY()){
				gt1set = true;
				break;
			}
		}
	}
}

void Item::createGate2(vector<Wall> wall, vector<Wall> immuneWall){
	bool gt2set = true;
	while(gt2set) {
		gate2X = rand() % 35 + 1;
		gate2Y = rand() % 35 + 1;

		for(int i = 0; i < wall.size(); i++) {
			if(gate2X == wall[i].getX() && gate2Y == wall[i].getY()) {
				if(gate2X != gate1X && gate2Y != gate1Y) {
					gt2set = false;
					break;
				}
			}
		}

		for(int i = 0; i < immuneWall.size(); i++){
			if(gate2X == immuneWall[i].getX() && gate2Y == immuneWall[i].getY()){
				gt2set = true;
				break;
			}
		}
	}
}

