#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Cut.h"
using namespace std;

void Cut::structs(string text) { //입력받은 text를 세개의 양수 l,r,h 한묶음씩 나눠 strArr벡터에 삽입하는 멤버함수
    char* buffer = new char[100];
    strcpy(buffer, text.c_str()); //char형 buffer에 text를 char형으로 바꿔 대입

    char* tok = strtok(buffer, "]"); //"]"를 기준으로 문자 나누기
    while (tok != NULL) {
        strArr.push_back(string(tok)); //strArr에 삽입
        tok = strtok(NULL, "]");
    }

    int size = strArr.size(); // 나눈 문자열에서 '['문자 빼기
    for (int i = 0; i < size; i++) {
        int index = strArr[i].find("[");
        if (index != -1) {
            strArr[i].replace(0, index + 1, "");
        }
    }

    for (int i = 0; i < size; i++) {//문자열에서 ']'문자 빼기
        int index = strArr[i].find("]");
        if (index != -1) {
            strArr[i].replace(index, index, "");
        }
    }
}

void Cut::strprint() { //나눠진 strArr벡터를 출력하는 멤버함수(코딩 도중 확인작업에 사용)
    int size = strArr.size();
    for (int i = 0; i < size; i++) {
        cout << strArr[i]<<"\n";
    }
}

void Cut::numcut() {//strArr에 나눠진 문자들을 순서대로 numArr배열에 숫자 변경 후 삽입하는 멤버함수
    int size = strArr.size();
    for (int i = 0; i < size; i++) {
        char* buffer = new char[100];
        strcpy(buffer, strArr[i].c_str());

        char* tok = strtok(buffer, ","); //","를 기준으로 문자 나누기
        while (tok != NULL) {
            int num = stoi(tok); //문자를 숫자로 변경
            numArr.push_back(size_t(num)); //numArr벡터에 삽입
            tok = strtok(NULL, ",");
        }
    }

}

void Cut::numprint() { //나눠진 numArr벡터를 출력하는 멤버함수(코딩 도중 확인작업에 사용)
    int size = numArr.size();
    for (int i = 0; i <size; i++) {
        cout << numArr[i]<< "\n";
    }
}