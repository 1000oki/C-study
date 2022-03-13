#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Cut.h"
using namespace std;

void Cut::structs(string text) { //�Է¹��� text�� ������ ��� l,r,h �ѹ����� ���� strArr���Ϳ� �����ϴ� ����Լ�
    char* buffer = new char[100];
    strcpy(buffer, text.c_str()); //char�� buffer�� text�� char������ �ٲ� ����

    char* tok = strtok(buffer, "]"); //"]"�� �������� ���� ������
    while (tok != NULL) {
        strArr.push_back(string(tok)); //strArr�� ����
        tok = strtok(NULL, "]");
    }

    int size = strArr.size(); // ���� ���ڿ����� '['���� ����
    for (int i = 0; i < size; i++) {
        int index = strArr[i].find("[");
        if (index != -1) {
            strArr[i].replace(0, index + 1, "");
        }
    }

    for (int i = 0; i < size; i++) {//���ڿ����� ']'���� ����
        int index = strArr[i].find("]");
        if (index != -1) {
            strArr[i].replace(index, index, "");
        }
    }
}

void Cut::strprint() { //������ strArr���͸� ����ϴ� ����Լ�(�ڵ� ���� Ȯ���۾��� ���)
    int size = strArr.size();
    for (int i = 0; i < size; i++) {
        cout << strArr[i]<<"\n";
    }
}

void Cut::numcut() {//strArr�� ������ ���ڵ��� ������� numArr�迭�� ���� ���� �� �����ϴ� ����Լ�
    int size = strArr.size();
    for (int i = 0; i < size; i++) {
        char* buffer = new char[100];
        strcpy(buffer, strArr[i].c_str());

        char* tok = strtok(buffer, ","); //","�� �������� ���� ������
        while (tok != NULL) {
            int num = stoi(tok); //���ڸ� ���ڷ� ����
            numArr.push_back(size_t(num)); //numArr���Ϳ� ����
            tok = strtok(NULL, ",");
        }
    }

}

void Cut::numprint() { //������ numArr���͸� ����ϴ� ����Լ�(�ڵ� ���� Ȯ���۾��� ���)
    int size = numArr.size();
    for (int i = 0; i <size; i++) {
        cout << numArr[i]<< "\n";
    }
}