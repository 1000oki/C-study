#ifndef CUT_H
#define CUT_H

#include <string>
#include <vector>
using namespace std;

class Cut { //�Էµ� ��ǥ�� ���ڷ� ��ȯ ������� �߶��ִ� Ŭ����
protected:
	vector<string> strArr; //l,r,h ������ string���� 
	vector<size_t> numArr; //strArr������ ������� ������������ ������ �°� �������ִ� ����
public:
	void structs(string text); //�Է¹��� text�� ������ ��� l,r,h �ѹ����� ���� strArr���Ϳ� �����ϴ� ����Լ�
	void strprint();  //������ strArr���͸� ����ϴ� ����Լ�(�ڵ� ���� Ȯ���۾��� ���)
	void numcut(); //strArr�� ������ ���ڵ��� ������� numArr�迭�� ���� ���� �� �����ϴ� ����Լ�
	void numprint(); //������ numArr���͸� ����ϴ� ����Լ�(�ڵ� ���� Ȯ���۾��� ���)
};
#endif
