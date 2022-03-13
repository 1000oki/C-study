#ifndef FRAME_H
#define FRAME_H

#include <string>
using namespace std;


class Frame {
private:
	int throw1; //ù��° ����
	int throw2; //�ι�° ���� 
	int throw3; //����° ����
	int score;  // �� �������� ����
	bool spare; //����� ���� 
	bool strike; //��Ʈ����ũ ����
public:
	Frame(); 
	void setScore(int value); //���� �������ִ� �Լ�
	void setFirstThrow(int value1); //ù��° ���� ���� �Լ�
	void setSecondThrow(int value2); //�ι�° ���� ���� �Լ�
	void setThirdThrow(int valu3); //����° ���� ���� �Լ�
	void setStrike(bool value); //��Ʈ����ũ ����
	void setSpare(bool value); //����� ����
	int getFirstThrow() { return throw1; } //ù��° ����
	int getSecondThrow() { return throw2; } //�ι�° ���� 
	int getThirdThrow() { return throw3; } //����° ����
	int getScore() { return score; } // �� �������� ����
	bool isStrike(); //��Ʈ����ũ ����
	bool isSpare(); //����� ����
};

#endif