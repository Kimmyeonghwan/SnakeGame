/**
 * @file main.cpp
 * @author 김명환(20181582), 임태민(20171690)
 * @brief 
 * @version 1.0
<<<<<<< HEAD
 * @date 2021-06-01
 */

#include <iostream>
#include <fstream>
#include "Map.h"
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <list>
#include <vector>
#include "Item.h"

using namespace std;

vector<Wall> wall;

bool isWall(int x, int y) {
	for(int i = 0; i < wall.size(); i++) {
		if(wall[i].getX() == x && wall[i].getY() == y) {
			return true;
			break;
		}
	}
	return false;
}


int main() {
	WINDOW* GameBoard;  //게임이 진행되는 창
	WINDOW* ScoreBoard; //점수가 보여지는 창
	WINDOW* MissionBoard; //미션 창
	WINDOW* MakerBoard; //제작자
	WINDOW* NextStage; //다음 스테이지 대기 창

	initscr();
	noecho();
	curs_set(0);
	keypad(stdscr, true);
	timeout(200);
	srand((unsigned int)time(NULL));

	start_color();
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	init_pair(2, COLOR_BLACK, COLOR_BLUE);

	list<Snake> snakeBody;
	list<Snake>::iterator it;
	vector<Wall> immuneWall;
	Map fin;
	fin.readFile();

	Map m = fin.convertGameMap();
	int wallX = 0, wallY = 0;
	auto mm = m.map;
	for (auto list : mm) {
		for (auto obj : list) {
			if(obj == 2){
				immuneWall.push_back(Wall(wallX++, wallY));
			}
			else if(obj == 1) {
				wall.push_back(Wall(wallX++, wallY));
			}
			else {
				wallX++;
			} 
			if(wallX > 35) {
				wallX = 0; wallY++;
			}
		}
	}
	for(int i = 0; i < immuneWall.size(); i++) cout << immuneWall[i].getX() << " " << immuneWall[i].getY() << endl;
	bool quit = false;
	int point = 0;
	int GrowItem = 0, PoisonItem = 0;
	int gateUsed = 0;

	int Level = 1;

	int dir = 2;
	int tail_dir = 0;
	
	Item item;
	item.createGrowth1(wall, it, snakeBody);
	item.createGrowth2(wall, it, snakeBody);
	item.createPoison(wall, it, snakeBody);

	bool passGate = true;
	int gc = 0;
	bool clear = false;
	
	int MissionsnakeBodyize = 5;
	int MissionGrowitem = 3;
	int MissionLimitedPoison = 10;
	int MaxsnakeBodyize = 3;
	int MaxGrowitem = 0;
	int MaxPoisonitem = 0;

	int ch;
	
	int itemTick = 0;
	int gateTick = 0;
	for(int i = 0; i < 3; i++) snakeBody.push_front(Snake(9, 11));

	while(!quit && Level != 5) {
    	ch = getch();
		switch (ch) {
			case KEY_LEFT:
				if(dir != 2 ) dir = 1;
				else tail_dir = 1;
				break;
			case KEY_RIGHT:
				if(dir != 1) dir = 2;
				else tail_dir = 1;
				break;
			case KEY_UP:
				if(dir != 4) dir = 3;
				else tail_dir = 1;
				break;
			case KEY_DOWN:
				if(dir!= 3) dir = 4;
				else tail_dir = 1;
				break;
			case 'q':
				quit = true;
				break;
    	}

		if(tail_dir == 1) quit = true;

		int x = 0, y = 0;
		Snake logic = snakeBody.front();
		x += logic.getX();
		y += logic.getY();

		if(dir == 1) x--;
		else if(dir == 2) x++;
		else if(dir == 3) y--;
		else if(dir == 4) y++;

		/* Gate Checker */
		if(gc >= snakeBody.size()) {
			passGate = true;
			gc = 0;
		}
		else {
			if(passGate == false) {
				gc++;
			}
		}

		itemTick++;
		gateTick++;
		/* GameBoard 설정 */
		GameBoard = newwin(36, 36.99, 1, 1);
		wbkgd(GameBoard, COLOR_PAIR(1));
		wattron(GameBoard, COLOR_PAIR(1));
		wborder(GameBoard, '|', '|', '-', '-', '#', '#', '#', '#');

		/* ScoreBoard 설정 */
		ScoreBoard = newwin(15, 34, 1, 45);
		wbkgd(ScoreBoard, COLOR_PAIR(1));
		wattron(ScoreBoard, COLOR_PAIR(1));
		mvwprintw(ScoreBoard, 1, 1, "          Score Board ");
		mvwprintw(ScoreBoard, 3, 1, "Total MaxsnakeBodyize : %i", MaxsnakeBodyize);
		mvwprintw(ScoreBoard, 5, 1, "Total GrowItem : %i", MaxGrowitem);
		mvwprintw(ScoreBoard, 6, 1, "Total PoisonItem : %i", MaxPoisonitem);
		mvwprintw(ScoreBoard, 7, 1, "Total gateUsed : %i", gateUsed);
		mvwprintw(ScoreBoard, 9, 1, "Your LEVEL : %i", Level);
		mvwprintw(ScoreBoard, 12, 1, "Total Point : %i", point);
		wrefresh(ScoreBoard);

		/* MissionBoard 설정 */
		MissionBoard = newwin(10, 34, 17, 45);
		wbkgd(MissionBoard, COLOR_PAIR(1));
		wattron(MissionBoard, COLOR_PAIR(1));
		mvwprintw(MissionBoard, 1, 1, "            Mission ");
		mvwprintw(MissionBoard, 3, 1, "snakeBodyize : %i / %i", snakeBody.size(), MissionsnakeBodyize);
		mvwprintw(MissionBoard, 5, 1, "Must get GrowItem : %i / %i",GrowItem, MissionGrowitem);
		mvwprintw(MissionBoard, 7, 1, "Don't get PoisonItem : %i / %i",PoisonItem, MissionLimitedPoison);
		mvwprintw(MissionBoard, 9, 1, "Pass Gate : %d", passGate);
		wrefresh(MissionBoard);

		/* MakerBoard 설정 */
		MakerBoard = newwin(9, 34, 28, 45);
		wbkgd(MakerBoard, COLOR_PAIR(1));
		wattron(MakerBoard, COLOR_PAIR(1));
		mvwprintw(MakerBoard, 1, 1, "             MaKer ");
		mvwprintw(MakerBoard, 3, 1, "Kim Myeonghwan(20181582)");
		mvwprintw(MakerBoard, 5, 1, "Lim Taemin(20171690)");
		wrefresh(MakerBoard);

		for(it = snakeBody.begin(); it != snakeBody.end();it++) {
			if(x == (*it).getX() && y == (*it).getY()) quit = true;
		}

		if(x == item.getGrowth1X() && y == item.getGrowth1Y()) {
			item.createGrowth1(wall, it, snakeBody);
			GrowItem++;
			point++;
		}
		else if(x == item.getGrowth2X() && y == item.getGrowth2Y()) {
			item.createGrowth2(wall, it, snakeBody);
			GrowItem++;
			point++;
		}
		else if(x == item.getPoisonX() && y == item.getPoisonY()) {
			item.createPoison(wall, it, snakeBody);
			snakeBody.pop_back();
			snakeBody.pop_back();
			PoisonItem++;
			point--;
		}
		else if(x == item.getGate1X() && y == item.getGate1Y()) {
			point++;
			gateUsed++;
			passGate = false;
			snakeBody.pop_back();
			x = item.getGate2X();
			y = item.getGate2Y();
			
			if(item.getGate2X() == 0 || item.getGate2X() == 35 || item.getGate2Y() == 0 || item.getGate2Y() == 35) { // 게이트가 테두리에 있을 때
				if (x == 0) {
					dir = 2; // 오른쪽
					x++;
				}
				else if (x == 35) {
					dir = 1; // 왼쪽
					x--;
				}
				else if (y == 0) {
					dir = 4; // 아래
					y++;
				}
				else if (y == 35) {
					dir = 3; // 위
					y--;
				}
			}
			else { // 게이트가 맵 안에 있을 때
				if(dir == 1) { //왼쪽으로 진입
					if(isWall(item.getGate2X()-1, item.getGate2Y())) { //왼쪽에 벽이 있는지 체크
						if(isWall(item.getGate2X(), item.getGate2Y()-1)) { // + 위쪽에 벽이 있는지 체크
							if(isWall(item.getGate2X()+1, item.getGate2Y())) { // + 오른쪽에 벽이 있는지 체크
								dir = 4;
								y++;
							}
							else { // 해당 사항 없으면 오른쪽으로 나감
								dir = 2;
								x++;
							}
						}
						else {
							dir = 3;
							y--;
						}
					}
					else {
						x--;
					}
				}
				else if(dir == 2) { //오른쪽으로 진입
					if(isWall(item.getGate2X()+1, item.getGate2Y())) { //오른쪽에 벽이 있는지 체크
						if(isWall(item.getGate2X(), item.getGate2Y()+1)) { // + 아래에 벽이 있는지 체크
							if(isWall(item.getGate2X()-1, item.getGate2Y())) { // + 왼쪽에 벽이 있는지 체크
								dir = 3;
								y--;
							}
							else { // 해당 사항 없으면 왼쪽으로 나감
								dir = 1;
								x--;
							}
						}
						else { // 
							dir = 4;
							y++;
						}
					}
					else {
						x++;
					}
				}
				else if(dir == 3) { // 위쪽으로 진입
					if(isWall(item.getGate2X(), item.getGate2Y()-1)) { //위쪽에 벽이 있는지 체크
						if(isWall(item.getGate2X()+1, item.getGate2Y())) { // + 오른쪽에 벽이 있는지 체크
							if(isWall(item.getGate2X(), item.getGate2Y()+1)) { // + 아래쪽에 벽이 있는지 체크
								dir = 1;
								x--;
							}
							else { // 해당 사항 없으면 아래쪽으로 나감
								dir = 4;
								y++;
							}
						}
						else { // 해당 사항 없으면 오른쪽으로 나감
							dir = 2;
							x++;
						}
					}
					else { // 해당 사항 없으면 위쪽으로 나감
						y--;
					}
				}
				else if(dir == 4) { // 아래쪽으로 진입
					if(isWall(item.getGate2X(), item.getGate2Y()+1)) { //아래쪽에 벽이 있는지 체크
						if(isWall(item.getGate2X()-1, item.getGate2Y())) { // + 왼쪽에 벽이 있는지 체크
							if(isWall(item.getGate2X(), item.getGate2Y()-1)) { // + 위쪽에 벽이 있는지 체크
								dir = 2; // 해당 사항 없으면 오른쪽으로 나감
								x++;
							}
							else { // 해당 사항 없으면 위쪽으로 나감
								dir = 3;
								y--;
							}
						}
						else { // 해당 사항 없으면 왼쪽으로 나감
							dir = 1;
							x--;
						}
					}
					else { // 해당 사항 없으면 아래쪽으로 나감
						y++;
					}
				}
			}
  		}
		else if(x == item.getGate2X() && y == item.getGate2Y()) {
			point++;
			gateUsed++;
			passGate = false;
			snakeBody.pop_back();
			x = item.getGate1X();
			y = item.getGate1Y();
			
			if(item.getGate1X() == 0 || item.getGate1X() == 35 || item.getGate1Y() == 0 || item.getGate1Y() == 35) { // 게이트가 테두리에 있을 때
				if (x == 0) {
					dir = 2; // 오른쪽
					x++;
				}
				else if (x == 35) {
					dir = 1; // 왼쪽
					x--;
				}
				else if (y == 0) {
					dir = 4; // 아래
					y++;
				}
				else if (y == 35) {
					dir = 3; // 위
					y--;
				}
			}
			else { // 게이트가 맵 안에 있을 때
				if(dir == 1) { // 왼쪽으로 진입
					if(isWall(item.getGate1X()-1, item.getGate1Y())) { //왼쪽에 벽이 있는지 체크
						if(isWall(item.getGate1X(), item.getGate1Y()-1)) { // + 위쪽에 벽이 있는지 체크
							if(isWall(item.getGate1X()+1, item.getGate1Y())) { // + 오른쪽에 벽이 있는지 체크
								dir = 4;
								y++;
							}
							else { // 해당 사항 없으면 오른쪽으로 나감
								dir = 2;
								x++;
							}
						}
						else {
							dir = 3;
							y--;
						}
					}
					else {
						x--;
					}
				}
				else if(dir == 2) { //오른쪽으로 진입
					if(isWall(item.getGate1X()+1, item.getGate1Y())) { //오른쪽에 벽이 있는지 체크
						if(isWall(item.getGate1X(), item.getGate1Y()+1)) { // + 아래에 벽이 있는지 체크
							if(isWall(item.getGate1X()-1, item.getGate1Y())) { // + 왼쪽에 벽이 있는지 체크
								dir = 3;
								y--;
							}
							else { // 해당 사항 없으면 왼쪽으로 나감
								dir = 1;
								x--;
							}
						}
						else { // 
							dir = 4;
							y++;
						}
					}
					else {
						x++;
					}
				}
				else if(dir == 3) { // 위쪽으로 진입
					if(isWall(item.getGate1X(), item.getGate1Y()-1)) { //위쪽에 벽이 있는지 체크
						if(isWall(item.getGate1X()+1, item.getGate1Y())) { // + 오른쪽에 벽이 있는지 체크
							if(isWall(item.getGate1X(), item.getGate1Y()+1)) { // + 아래쪽에 벽이 있는지 체크
								dir = 1;
								x--;
							}
							else { // 해당 사항 없으면 아래쪽으로 나감
								dir = 4;
								y++;
							}
						}
						else { // 해당 사항 없으면 오른쪽으로 나감
							dir = 2;
							x++;
						}
					}
					else { // 해당 사항 없으면 위쪽으로 나감
						y--;
					}
				}
				else if(dir == 4) { // 아래쪽으로 진입
					if(isWall(item.getGate1X(), item.getGate1Y()+1)) { //아래쪽에 벽이 있는지 체크
						if(isWall(item.getGate1X()-1, item.getGate1Y())) { // + 왼쪽에 벽이 있는지 체크
							if(isWall(item.getGate1X(), item.getGate1Y()-1)) { // + 위쪽에 벽이 있는지 체크
								dir = 2; // 해당 사항 없으면 오른쪽으로 나감
								x++;
							}
							else { // 해당 사항 없으면 위쪽으로 나감
								dir = 3;
								y--;
							}
						}
						else { // 해당 사항 없으면 왼쪽으로 나감
							dir = 1;
							x--;
						}
					}
					else { // 해당 사항 없으면 아래쪽으로 나감
						y++;
					}
				}
			}
		}
		else
			snakeBody.pop_back(); // 스네이크 이동

		for(int i = 0; i < wall.size(); i++) mvwaddch(GameBoard, wall[i].getY(), wall[i].getX(), '#');
		for(int i = 0; i < immuneWall.size(); i++) mvwaddch(GameBoard, immuneWall[i].getY(), immuneWall[i].getX(), '%');

		mvwaddch(GameBoard, item.getGate1Y(), item.getGate1X(), '@');
		mvwaddch(GameBoard, item.getGate2Y(), item.getGate2X(), '@');

		snakeBody.push_front(Snake(x, y)); // 스네이크 이동

		if(y > 36 || x > 36 || y < 1 || x < 1) quit = true; // GameBoard 창 넘어가면 게임오버
		for(int i = 0; i < wall.size(); i++) {
			if(x == wall[i].getX() && y == wall[i].getY()) quit = true;
		}
		
		mvwaddch(GameBoard, item.getGrowth1Y(), item.getGrowth1X(), '+'); // Growth아이템 생성1
		mvwaddch(GameBoard, item.getGrowth2Y(), item.getGrowth2X(), '+'); // Growth아이템 생성2
		mvwaddch(GameBoard, item.getPoisonY(), item.getPoisonX(), '-'); // Poison아이템 생성1
		wrefresh(GameBoard);

		if(itemTick > 59) { // 60틱마다 모든 아이템 재생성
			item.createGrowth1(wall, it, snakeBody);
			item.createGrowth2(wall, it, snakeBody);
			item.createPoison(wall, it, snakeBody);
			itemTick = 0;
		}

		if(gateTick > 89 && Level >= 2) { // 2스테이지 이상 + 90틱마다 게이트 재생성
			if(passGate) {
				item.createGate1(wall, immuneWall);
				item.createGate2(wall, immuneWall);
				gateTick = 0;
			}	
		}

		for(it = snakeBody.begin(); it != snakeBody.end(); it++){
			mvwaddch(GameBoard, (*it).getY(), (*it).getX(), '*'); // snake
		}
		wrefresh(GameBoard);
  
		/* Max 계산 */
		if(snakeBody.size() >= MaxsnakeBodyize) MaxsnakeBodyize = snakeBody.size();
		if(GrowItem >= MaxGrowitem) MaxGrowitem = GrowItem;
		if(PoisonItem >= MaxPoisonitem) MaxPoisonitem = PoisonItem;

		if(snakeBody.size() < 3) quit = true;
		if(PoisonItem == MissionLimitedPoison) quit = true; // Poison 아이템 횟수 제한 오버
		/* Stage Clear!! */
		if(GrowItem >= MissionGrowitem && snakeBody.size() >= MissionsnakeBodyize && PoisonItem < MissionLimitedPoison && Level < 5) {
			/* Max 계산 */
			if(snakeBody.size() >= MaxsnakeBodyize) MaxsnakeBodyize = snakeBody.size();
			if(GrowItem >= MaxGrowitem) MaxGrowitem = GrowItem;
			if(PoisonItem >= MaxPoisonitem) MaxPoisonitem = PoisonItem;

			snakeBody.clear();
			for(int i = 0; i < 3; i++) snakeBody.push_front(Snake(9, 11)); // Snake 사이즈 및 위치 초기화
			
			/* 난이도 급상승! */
			MissionsnakeBodyize += (rand() % 3) + 1;
			MissionGrowitem += (rand() % 3) + 1;
			MissionLimitedPoison -= (rand() % 2) + 1;
			
			/* 맵 데이터 변수 초기화 */
			GrowItem = 0;
			PoisonItem = 0;
			gateUsed = 0;
			dir = 2;
			wall.clear();
			immuneWall.clear();

			/* 새로운 스테이지의 맵 불러오기 */
			fin.readFile();

			m = fin.convertGameMap();
			int wallX = 0, wallY = 0;
			auto mm = m.map;
			for (auto list : mm) {
				for (auto obj : list) {
					if(obj == 2){
						immuneWall.push_back(Wall(wallX++, wallY));
					}
					else if(obj == 1) {
						wall.push_back(Wall(wallX++, wallY));
					}
					else {
						wallX++;
					} 
					if(wallX > 35) {
						wallX = 0; wallY++;
					}
				}
			}
			
			Level +=1;
			if(Level >= 2) { // 레벨이 2단계 이상이면 (2스테이지 이상이면) 게이트 생성
				item.createGate1(wall, immuneWall);
				item.createGate2(wall, immuneWall);
			}
			NextStage = newwin(10, 34, 13, 2.5);
			wbkgd(NextStage, COLOR_PAIR(2));
			wattron(NextStage, COLOR_PAIR(2));
			mvwprintw(NextStage, 2, 2, "         Stage Clear");
			mvwprintw(NextStage, 5, 1, "Press any key to Play Next Stage.");
			wrefresh(NextStage);
			getchar();
			werase(NextStage);
			delwin(NextStage);
			
			
		}
		
		if(Level == 5){
			quit = true;
			clear = true;
			erase();
			mvprintw(1, 1, "<< congratulations! >>");
			mvprintw(2, 1, "<< You have cleared this game!! >>");
			mvprintw(3, 1, "The maximum size of your snake is %i.", MaxsnakeBodyize);
			mvprintw(4, 1, "You gained a total of %i GrowItem.", MaxGrowitem);
			mvprintw(5, 1, "You gained a total of %i PoisonItem.", MaxPoisonitem);
			mvprintw(8, 1, "Your Total Score :  %i", point);
			mvprintw(12, 1, "Press any key to end the game.");
			refresh();
			getchar();
		}
	}
	
	erase();
	if(clear == false){
		mvprintw(1, 1, "The maximum size of your snake is %i.", MaxsnakeBodyize);
		mvprintw(2, 1, "You gained a total of %i GrowItem.", MaxGrowitem);
		mvprintw(3, 1, "You gained a total of %i PoisonItem.", MaxPoisonitem);
		mvprintw(6, 1, "Your Total_Point : %i", point);  
		mvprintw(11, 1, "Press any key to end the game.");
		refresh();
		getchar();
	}
	delwin(GameBoard);
	delwin(ScoreBoard);
	delwin(MissionBoard);
	delwin(MakerBoard);
	endwin();
	return 0;

}

