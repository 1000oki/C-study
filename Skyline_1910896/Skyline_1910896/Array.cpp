#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include<stdlib.h>
#include "Array.h"
#include "Cut.h"
#include "Skyline.h"
using namespace std;

void Array::resultArray() { //모든 결과 출력 멤버함수
	string text; //입력받은 문자열 넣어줄 변수
	while (true) { //정상적인 입력을 하지 않았을 경우 반복
		cout << "입력 : "; 
		strArr.clear(); //오류 났을 시 다시 반복을 위해 strArr벡터의 내용 삭제
		numArr.clear(); //오류 났을 시 다시 반복을 위해 numArr벡터의 내용 삭제
		getline(cin, text); //한줄로 문자 입력
		structs(text); //Cut클래스에서 상속 받은 멤버 함수로 text를 세개의 양수 l,r,h 한묶음씩 나눠 strArr벡터에 삽입
		numcut(); //Cut클래스에서 상속 받은 멤버 함수로 strArr에 나눠진 문자들을 순서대로 numArr배열에 숫자 변경 후 삽입
		int i = 0;
		int size = numArr.size();
		int absolute = numArr[i + 1] - numArr[i]; 
		bool result = 1; //조건을 만족하는지 확인

		while (i < size) { //입력된 문자열 조건확인 
			if (numArr[i] <= numArr[i + 1] && numArr[i] > 0 && numArr[i + 1] <= 255 && abs(absolute) >= 1 && abs(absolute) <= 104 && numArr[i + 2] <= 255 && numArr[i + 2]) {
				result = 1;
			}
			else {
				result = 0;
				break;
			}
			i += 3;
		}

		if (result == true) { //조건이 맞다면 출력
			for (int i = 0; i < size; i += 3) { //Skyline의 add호출해서 height벡터의 크기와 height벡터의 원소 삽입(numArr배열에 저장한 것을 순서대로 삽입)
				sky.add(numArr[i], numArr[i + 1], numArr[i + 2]); 
			}

			cout << "출력 : ";	//결과 출력
			vector<pair<size_t, size_t>> g; 
			g = sky.getAsSequence(); 
			sky.printSkyline(); //Skyline의 배열 출력 함수 호출

			cout << "\n\n건물\n";	//건물 그래프 출력
			for (int i = 0; i < size; i += 3) { //Draw클래스에서 상속받아 numArr배열 저장한 것을 각각의 벡터에 삽입
				addgraph(numArr[i], numArr[i + 1], numArr[i + 2]);
			}
			vector<tuple<size_t, size_t, size_t>> s;
			s = getAslrh(); //Draw클래스에서 상속받은 getAslrh()함수로 입력된 좌표를 (l,r,h)세쌍을 벡터에 저장후 s에 대입
			graph(s); //Draw클래스에서 상속받아은 graph함수로 건물을 그래프 그림
			printgraph(); //Draw클래스에서 상속받아은 printgraph함수로 그래프 출력

			cout << "\n\n건물의 윤곽\n";
			length(g); //Draw클래스에서 상속받은 length함수로 건물의 윤곽 그래프 그림
			printl_w(); //Draw클래스에서 상속받은 printl_w함수로 그래프 출력
			break; //반복문을 빠져나가 프로그램 종료
		}
		else { //조건이 틀리면 출력후, 반복문을 빠져나가지 못하고 다시 실행
			cout << "조건에 알맞지 않습니다!\n[조건] \n1 <= buildings.length <= 104\n0 <= left[i] < right[i] <= 255\n1 <= height[i] <= 255\n다시 입력하십시오.\n";
		}
	}
};