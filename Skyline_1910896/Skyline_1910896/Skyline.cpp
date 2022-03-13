#include <iostream>
#include <string>
#include "Skyline.h"
using namespace std;

void Skyline::add(size_t l, size_t r, size_t h) { //height벡터의 크기와 height벡터의 원소 삽입
	if (r > height.size()) { //오른쪽 x값이 height벡터 크기보다 크면
		height.resize(r); //오른쪽 x값만큼 height벡터의 크기를 재할당해준다.
	}
	for (size_t i = l; i != r; ++i) { //왼쪽 x값부터 오른쪽 x값까지 h값이 height[i]값보다 클경우
		if (h > height[i]) { 
			height[i] = h;
		}
	}
}

vector<pair<size_t, size_t>> Skyline::getAsSequence() const //높이의 값이 변했을 때의 (x,y)쌍의 좌표로 리턴해주는 함수
{
	vector<pair<size_t, size_t>> get;
	size_t prev = 0;  //위치 지정해줄 포인터
	for (size_t i = 0; i != height.size(); ++i) {  
		if (height[i] != prev) { //높이가 이전 높이와 같지 않을 때
			get.push_back(make_pair(i, height[i])); //i는 x값, height[i]는 y값으로 삽입
			prev = height[i]; //포인터 이동
		}
	}
	get.push_back(make_pair(height.size(), 0)); //마지막은 x는 height의 크기, y는 0으로 삽입
	return get; 
}

void Skyline::printSkyline() //Skyline의 배열 출력 함수
{
	get1 = getAsSequence();
	int size = get1.size();
	for (int i = 0; i < size; i++) {
		cout << "[" << get1[i].first << "," << get1[i].second << "] ";
		if (i != get1.size() - 1) {
			cout << ",";
		}
	}
}



