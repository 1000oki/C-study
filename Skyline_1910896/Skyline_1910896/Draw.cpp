#include <iostream>
#include <string>
#include<stdlib.h> 
#include "Draw.h"
#include <tuple>
using namespace std;


void Draw::addgraph(size_t l, size_t r, size_t h) //입력된 좌표를 각각의 벡터에 저장시켜주는 멤버함수
{
	le.push_back(l); //왼쪽 좌표(l) le벡터함수에 삽입
	ri.push_back(r); //오른쪽 좌표(r) ri벡터함수에 삽입 
	he.push_back(h); //높이 좌표(h) he벡터함수에 삽입
}

vector<tuple<size_t, size_t, size_t>> Draw::getAslrh() const{ //입력된 좌표를 (l,r,h)세쌍을 벡터로 리턴해주는 멤버함수
	vector<tuple<size_t, size_t, size_t>>get;  
	int size = le.size();  //좌표의 길이
	for (int i = 0; i < size; i++) { //왼쪽, 오른쪽, 높이를 get벡터 변수에 삽입
		get.push_back(make_tuple(le[i],ri[i],he[i]));
	}
	return get; //get으로 리턴
}

void Draw::graph(vector<tuple<size_t, size_t, size_t>> lrh) //건물을 그래프로 그려주는 멤버함수
{
	max_w = 0;  //x좌표의 최대값 초기화
	max_h = 0;  //y좌표의 최대값 초기화
	int size = lrh.size();  
	for (int i = 0; i < size; i++) { //max_w, max_h에 x좌표, y좌표의 최댓값 구해서 삽입
		int w = get<1>(lrh[i]);  
		int h = get<2>(lrh[i]);
		if (max_w < w) {
			max_w = get<1>(lrh[i]);
		}
		if (max_h < h) {
			max_h =  get<2>(lrh[i]);
		}
	}
	

	for (int i = max_h+5; i >= 0; i--) { //건물 그래프 배열의 모든 곳에 '.'으로 초기화
		for (int j = 0; j < max_w+5; j++) {
			arrgraph[i][j] = '.';
		}
	}

	for (int i = lrh.size()-1; i >= 0; i--) { //앞쪽에 있는 건물이 뒷쪽에 있는 건물을 가리고, 먼저 입력된 배열이 앞쪽으로 위치함으로 lrh벡터를 마지막 원소부터 반대로 출력
		int row = get<2>(lrh[i]); //각 원소의 2번은 y
		int col1 = get<0>(lrh[i]); //각 원소의 0번은 왼쪽x
		int col2 = get<1>(lrh[i]); //각 원소의 1번은 오른쪽x
		for (int j = 0; j < row+1; j++) { //각 원소의 높이만큼 l를 배열에 처장		
			arrgraph[j][col1] = 'l'; 
			arrgraph[j][col2] = 'l';

			for (int k = col1 + 1; k < col2; k++) { //앞쪽에 있는 건물이 뒷쪽에 있는 건물을 가리기 때문에 앞쪽 건물이 추가 될때마다 앞쪽 건물 안에 뒷쪽 건물이 위치하는 부분은 '.'부분으로 변경
				if (arrgraph[j][k] != '.') {
					arrgraph[j][k] = '.';
				}
			}
		}
		for (int j = col1 + 1; j < col2; j++) { //각 원소의 가로 길이(col1부터 col2까지) 만큼 '_' 배열에 저장
			if (arrgraph[row + 1][j] == 'l') { //모양을 위해서 'l'이 위치했던 부분은 그대로 'ㅣ'로 둔다.
				arrgraph[row + 1][j] = 'l';
			}
			else {
				arrgraph[row + 1][j] = '_'; //그렇지 않은 부분만 '_'로 배열에 저장
			}
		}
	}

	for (int j = 0; j < max_w + 5; j++) { //X축의 밑부분을 표시하기 위해 '_'배열에 저장
		if (arrgraph[1][j] == '.') {
			arrgraph[1][j] = '_';
		}
	}
}

void Draw::printgraph() //건물 그래프를 출력해주는 멤버함수
{
	for (int i = max_h + 5; i > 0; i--) { //y축의 길이는 최대 y의 길이보다 +5해준 만큼
		for (int j = 1; j < max_w + 5; j++) { //x축의 길이는 최대 x길이보다 +5해준 만큼
			cout << arrgraph[i][j]; //그래프 출력
		}
		cout << "\n";
	}
}

void Draw::length(vector<pair<size_t, size_t>> length_width) //건물의 윤곽 그래프를 그려주는 멤버함수
{
	
	for (int i = max_h + 5; i > 0; i--) { //건물 윤관 그래프 배열의 모든 곳에 .으로 초기화
		for (int j = 0; j < max_w + 5; j++) {
			arrline[i][j]= '.';
		}
	}

	int h = length_width[0].second ; //건물의 높이
	for (int i = 0; i < h+1; i++) { //첫 첫번째건물의 높이만큼 'l' 배열에 저장
		arrline[i][length_width[0].first] = 'l'; 
	}
	int size = length_width.size();  //length_width벡터의 크기
	for (int i = 1; i <size; i++) {   //세로 그래프 생성
		int l = length_width[i].second - length_width[i - 1].second; //직전 벡터원소와의 y위치 차이
		int h1 = length_width[i-1].second; //직전 벡터원소의 y위치
		int w = length_width[i].first; //벡터 원소의 x위치
		if (l < 0) { //직전 벡터원소와의 y위치 차이가 0보다 작으면
			for (int j = h1; j > h1 + l; j--) { //직전 벡터원소의 y위치에서 현재 벡터원소의 y위치로 내려오면서 'l'를 삽입
				arrline[j][w] = 'l';
			}
		}
		else { //직전 벡터원소와의 차이가 0보다 크면
			for (int j = h1 + 1; j < h1 + l + 1; j++) { //직전 벡터원소의 y위치에서 현재 벡터원소의 y위치로 올리가면서 'ㅣ'를 삽입
				arrline[j][w] = 'l';
			}
		}
	}
	
	for (int i = 1; i < size; i++) { //가로 그래프 생성
		int w2 = length_width[i].first ;  
		for (int j = length_width[i-1].first+1; j < w2 ; j++) { //직전 벡터원소의 x위치+1부터 현재 벡터원소의 x위치까지 '_'삽입
			arrline[length_width[i-1].second+1][j] = '_';
		}
	}
	for (int j = 0; j < max_w + 5; j++) { //X축의 밑부분을 표시하기 위해 '_'배열에 저장
		if (arrline[1][j] =='.') {
			arrline[1][j] = '_';
		}
	}
}


void Draw::printl_w() //건물의 윤곽 그래프를 출력해주는 멤버함수
{
	for (int i = max_h + 5; i >0; i--) {//y축의 길이는 최대 y의 길이보다 +5해준 만큼
		for (int j = 1; j < max_w + 5; j++) { //x축의 길이는 최대 x길이보다 +5해준 만큼
			cout<< arrline[i][j]; //그래프 출력
		}
		cout << "\n";
	}
}
