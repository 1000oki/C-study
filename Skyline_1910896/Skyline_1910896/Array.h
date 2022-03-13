#ifndef ARRAY_H
#define ARRAY_H

#include <string>
#include <vector>
using namespace std;

#include "Cut.h"
#include "Skyline.h"
#include "Draw.h"

class Array : public Cut, public Draw{ //전체 배열 및 그림 출력 클래스(Cut,Draw클래스 상속)
	Skyline sky; 
	vector<pair<size_t, size_t> > out; //Skyline의 getAsSequence()멤버함수 저장해줄 변수
public:
	void resultArray(); //모든 결과 출력 멤버함수
};

#endif