#include <iostream>
#include <ncurses.h>
#include "Screen/StartScreen.h"
#include "Input/KeyBoardInput.h"
#include "Input/FileInput.h"

using namespace std;


int main(int argc, char *argv[])
{
	StartScreen();
/*
     FileInput fin;
     fin.readFile();

     GameMap m = fin.convertGameMap();

     auto mm = m.map;
     for (auto list : mm) {
         for (auto obj : list) {
             cout << obj;
         }
         cout << endl;
     }
	 */
}
