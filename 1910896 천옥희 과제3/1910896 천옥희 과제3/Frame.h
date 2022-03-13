#ifndef FRAME_H
#define FRAME_H

#include <string>
using namespace std;


class Frame {
private:
	int throw1; //첫번째 점수
	int throw2; //두번째 점수 
	int throw3; //세번째 점수
	int score;  // 각 프레임의 점수
	bool spare; //스페어 여부 
	bool strike; //스트라이크 여부
public:
	Frame(); 
	void setScore(int value); //점수 정의해주는 함수
	void setFirstThrow(int value1); //첫번째 점수 정의 함수
	void setSecondThrow(int value2); //두번째 점수 정의 함수
	void setThirdThrow(int valu3); //세번째 점수 정의 함수
	void setStrike(bool value); //스트라이크 정의
	void setSpare(bool value); //스페어 정의
	int getFirstThrow() { return throw1; } //첫번째 점수
	int getSecondThrow() { return throw2; } //두번째 점수 
	int getThirdThrow() { return throw3; } //세번째 점수
	int getScore() { return score; } // 각 프레임의 점수
	bool isStrike(); //스트라이크 여부
	bool isSpare(); //스페어 여부
};

#endif