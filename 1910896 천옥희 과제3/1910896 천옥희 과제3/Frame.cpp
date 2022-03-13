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

void Frame::setScore(int value) { //점수 정의해주는 함수
	score = value;
}

void Frame::setFirstThrow(int value1){ //첫번째 점수 정의 함수
	throw1 = value1;
}

void Frame::setSecondThrow(int value2) {//두번째 점수 정의 함수
	throw2 = value2;
}

void Frame::setThirdThrow(int value3) { //세번째 점수 정의 함수
	throw3 = value3;
}

void Frame::setStrike(bool value) { //스트라이크 정의
	strike = value;
}

void Frame::setSpare(bool value) { //스페어 정의
	spare = value;
}

bool Frame::isSpare() { //스트라이크 여부
	return spare;
}

bool Frame::isStrike() { //스페어 여부
	return strike;
}
