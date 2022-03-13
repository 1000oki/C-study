#ifndef CUT_H
#define CUT_H

#include <string>
#include <vector>
using namespace std;

class Cut { //입력된 좌표를 숫자로 변환 순서대로 잘라주는 클래스
protected:
	vector<string> strArr; //l,r,h 형식의 string벡터 
	vector<size_t> numArr; //strArr벡터의 멤버들을 숫자형식으로 순서에 맞게 삽입해주는 벡터
public:
	void structs(string text); //입력받은 text를 세개의 양수 l,r,h 한묶음씩 나눠 strArr벡터에 삽입하는 멤버함수
	void strprint();  //나눠진 strArr벡터를 출력하는 멤버함수(코딩 도중 확인작업에 사용)
	void numcut(); //strArr에 나눠진 문자들을 순서대로 numArr배열에 숫자 변경 후 삽입하는 멤버함수
	void numprint(); //나눠진 numArr벡터를 출력하는 멤버함수(코딩 도중 확인작업에 사용)
};
#endif
