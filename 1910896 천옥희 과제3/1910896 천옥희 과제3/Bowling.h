#ifndef BOWLING_H
#define BOWLING_H

#include <string>
using namespace std;

#include "Frame.h"

class Bowling { 
	int number; //������ ������ ��ȣ
protected:
	Frame a[10]; 
public:
	Bowling() { number = 0; } //Bowling�ʱ�ȭ
	void setnumber(int value) { number = value; } //number����
	int getnumber() { return number; } //number ��ȣ
	void calculateScore(); //�� �������� ���� ���
	void bowl(); //��Ʈ����ũ, ����� ����
	void printData(); //�� �������� ���� ���
};

#endif