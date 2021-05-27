#include <iostream>
#include <ncurses.h>
#include "Screen/StartScreen.h"
#include "Input/KeyBoardInput.h"

using namespace std;


int main(int argc, char *argv[])
{
	initscr();
	noecho();
	//keypad(stdscr, TRUE);
	cout << KeyBoardInput::getInput() << '\n';
}

