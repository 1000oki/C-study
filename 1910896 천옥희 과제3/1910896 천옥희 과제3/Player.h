#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

#include "Bowling.h"

class Player :public Bowling {  // BowlingŬ���� ���
	string name;   //player�� �̸� 
public:
	Player() { this->name = ""; } 
	string getName() { return name; } //PlayerŬ������ �̸� �޾ƿ��� �Լ�
	void setName(string name) { this->name = name; } //PlayerŬ������ �̸� �����ϴ� �Լ�
	void showScore(); //��� �������� ���� ���������ִ� �Լ�
	void showTotalFrame(); //������ ���� �� ������ ������ ���·� �����ִ� �Լ�
};

#endif