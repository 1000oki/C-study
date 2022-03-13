#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

#include "Bowling.h"

class Player :public Bowling {  // Bowling클래스 상속
	string name;   //player의 이름 
public:
	Player() { this->name = ""; } 
	string getName() { return name; } //Player클래스의 이름 받아오는 함수
	void setName(string name) { this->name = name; } //Player클래스의 이름 정의하는 함수
	void showScore(); //모든 프레임의 볼링 점수보여주는 함수
	void showTotalFrame(); //볼링의 점수 및 총합의 프레임 형태로 보여주는 함수
};

#endif