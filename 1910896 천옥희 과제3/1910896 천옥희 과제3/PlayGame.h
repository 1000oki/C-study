#ifndef PLAYGAME_H
#define PLAYGAME_H

#include <string>
using namespace std;

#include "Player.h"

class PlayGame{
	int numberOfPlayer;	//플레이어 수
	Player p[2]; //Player

public:
	void gameStart(); //게임 출력함수
};

#endif