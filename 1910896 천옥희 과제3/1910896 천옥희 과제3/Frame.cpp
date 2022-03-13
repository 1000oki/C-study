#include <iostream>
#include <string>
#include "Frame.h"
using namespace std;

Frame::Frame(){
	throw1 = 0;
	throw2 = 0;
	throw3 = 0;
	score = 0;
	spare = false;
	strike = false;
}

void Frame::setScore(int value) { //���� �������ִ� �Լ�
	score = value;
}

void Frame::setFirstThrow(int value1){ //ù��° ���� ���� �Լ�
	throw1 = value1;
}

void Frame::setSecondThrow(int value2) {//�ι�° ���� ���� �Լ�
	throw2 = value2;
}

void Frame::setThirdThrow(int value3) { //����° ���� ���� �Լ�
	throw3 = value3;
}

void Frame::setStrike(bool value) { //��Ʈ����ũ ����
	strike = value;
}

void Frame::setSpare(bool value) { //����� ����
	spare = value;
}

bool Frame::isSpare() { //��Ʈ����ũ ����
	return spare;
}

bool Frame::isStrike() { //����� ����
	return strike;
}
