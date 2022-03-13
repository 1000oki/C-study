#ifndef BOWLING_H
#define BOWLING_H

#include <string>
using namespace std;

#include "Frame.h"

class Bowling { 
	int number; //볼링의 프레임 번호
protected:
	Frame a[10]; 
public:
	Bowling() { number = 0; } //Bowling초기화
	void setnumber(int value) { number = value; } //number정의
	int getnumber() { return number; } //number 번호
	void calculateScore(); //각 프레임의 점수 계산
	void bowl(); //스트라이크, 스페어 정의
	void printData(); //각 프레임의 점수 출력
};

#endif