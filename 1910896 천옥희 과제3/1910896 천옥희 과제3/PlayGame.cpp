#include <iostream>
#include <string>
#include "PlayGame.h"
#include "Bowling.h"
#include "Frame.h"
#include "Player.h"


using namespace std;

void PlayGame::gameStart(){ //���� ����Լ�
	cout << "���������� �����մϴ�. �÷��̾�� �� ���Դϱ�?";
	cin >> numberOfPlayer;
	string name[2];
	for (int i = 0; i < numberOfPlayer; i++) {	//numberOfPlayer��ŭ �÷��̾� �̸� �Է¹ޱ�
		cout << "\n"<<i+1<<"��° �÷��̾��� �̸��� ? ";
		cin >> name[i];	//name[i]�� �̸� �Է¹���
		p[i].setName(name[i]); //PlayerŬ������ setName�� ���� p[i]�� �̸� ���� 
	}

	cout << "\n\nWelcome to Sookmyung Bowling Club!!\n Let's start a Bowling Game!!\n";
	for (int j = 0; j < 10; j++) {	
		p[0].setnumber(j);	//�÷��̾� 1,2�� setnumber�� ���� ������ ���� ������ �� �ֵ��� ��.
		p[1].setnumber(j);
		for (int i = 0; i < numberOfPlayer; i++) {
				cout << "\n" << p[i].getName() << "���� "; 
				if (i == 0) {	
					p[i].printData();
				}
				else {
					p[i].printData();
			}
		}
	}

	p[0].calculateScore(); // �� �÷��̾��� ���� ���
	p[1].calculateScore();
	
	cout << "\n�̸�\t";     //������ ���� ������ ���
	for (int i = 0; i < 10; i++) {
		cout << i+1 << "\t";
	}
	cout << "�հ�" << endl;
	cout << p[0].getName()<<"\t";
	p[0].showTotalFrame();
	cout << "\n" << p[1].getName() << "\t";
	p[1].showTotalFrame();

}