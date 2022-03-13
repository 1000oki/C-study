#ifndef DRAW_H
#define DRAW_H

#include <string>
#include <vector>
using namespace std;

class Draw { //그래프 그리는 클래스
	int max_w; //그래프출력 시 가로길이를 오른쪽 x좌표 중 가장 큰 값으로 정하기 위해 필요한 변수
	int max_h; //그래프출력 시 가로길이를 y좌표 중 가장 큰 값으로 정하기 위해 필요한 변수
	char arrgraph[255][255]; //건물을 그래프로 표현하기 위한 벡터
	char arrline[255][255];  //건물의 윤곽을 그래프로 표현하기 위한 벡터
	vector<size_t> le; //왼쪽(l) x좌표를 저장해줄 벡터
	vector<size_t> ri; //오른쪽(r) x좌표를 저장해줄 벡터
	vector<size_t> he; //높이(h) y좌표를 저장해줄 벡터

public:
	void addgraph(size_t l, size_t r, size_t h); //입력된 좌표를 각각의 벡터에 저장시켜주는 멤버함수
	vector<tuple<size_t, size_t, size_t>> getAslrh() const; //입력된 좌표를 (l,r,h)세쌍을 벡터에 저장해주는 멤버함수
	void graph(vector<tuple<size_t, size_t, size_t>> lrh); //건물을 그래프로 그려주는 멤버함수
	void printgraph(); //건물 그래프를 출력해주는 멤버함수
	void length(vector<pair<size_t, size_t> > length_width); //건물의 윤곽 그래프를 그려주는 멤버함수
	void printl_w(); //건물의 윤곽 그래프를 출력해주는 멤버함수
};
#endif