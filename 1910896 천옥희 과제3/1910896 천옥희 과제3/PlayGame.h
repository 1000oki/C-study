#ifndef PLAYGAME_H
#define PLAYGAME_H

#include <string>
using namespace std;

#include "Player.h"

class PlayGame{
	int numberOfPlayer;	//�÷��̾� ��
	Player p[2]; //Player

public:
	void gameStart(); //���� ����Լ�
};

#endif