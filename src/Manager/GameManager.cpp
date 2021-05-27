/**
 * @file GameManager.cpp
 * @author 배용하(20191602)
 * @brief Implementation of GameManager
 * @version 1.0
 * @date 2021-05-28
 * 
 */

#include "Manager/GameManager.h"

GameManager::GameManager()
{
    
}

GameManager::~GameManager()
{

}

int GameManager::getElapsedTime()
{
    return elapsedTime;
}

void GameManager::addElapsedTime(int t = 1)
{
    elapsedTime += t;
}

void GameManager::updateGame()
{

}

