#include <iostream>
#include <string>
#include "Player.h"
using namespace std;


void Player::showScore() { //��� �������� ���� ���������ִ� �Լ�
	for (int i = 0; i < 10; i++) {
		if (i == 9) { // 10��° �������� ��
			if (a[9].isSpare() || a[9].isStrike()) { //��Ʈ����ũ �Ǵ� ������� ��
				string score1, score2, score3;
				if (a[9].isStrike()) { //ù ��°�� ��Ʈ����ũ�� ���(a[i].isStrike�� Bowling���� ��� ����)
					if (a[9].getSecondThrow() == 10) { //2��° ������ 10�� ��
						if (a[9].getThirdThrow() == 10) { //3��° ������ 10�� ��
							cout << "X X X";
						}
						else { //3��° ������ 10�� �ƴ� ��
							cout << "X X " << a[9].getThirdThrow();
						}
					}
					else { //ù��°�� ��Ʈ����ũ�� �ƴ� ��
						if (a[9].getSecondThrow() + a[9].getThirdThrow() == 10) { //�ι�° ������ ����° ������ ���� 10�� ��
							cout << "X " << a[9].getSecondThrow() << " /";
						}
						else {	//���� 10�� �ƴ� ��
							cout << "X " << a[9].getSecondThrow() << " " << a[9].getThirdThrow();
						}
					}
				}
				else if (a[9].isSpare()) { //������� ���(a[i].isSpare�� Bowling���� ��� ����)
					if (a[9].getThirdThrow() == 10) { //����° ������ 10�� ��
						cout << a[9].getFirstThrow() << " / X";
					}
					else { //���� ° ������ 10�� �ƴ� ��
						cout << a[9].getFirstThrow() << " / " << a[9].getThirdThrow();
					}
				}
			}
			else { //��Ʈ����ũ�� ���� �ƴ� ���
				cout << a[9].getFirstThrow() << " " << a[9].getSecondThrow();
			}
		}
		else {
			if (a[i].isStrike()) { //��Ʈ����ũ�� ���(a[i].isStrike�� Bowling���� ��� ����)
				cout << "X ";  //X�� ���
			}
			else {
				if (a[i].isSpare()) { //������� ���(a[i].isSpare�� Bowling���� ��� ����)
					cout << a[i].getFirstThrow() << " /";
				}
				else { //��Ʈ����ũ�� ���� �ƴ� ���
					cout << a[i].getFirstThrow() << " " << a[i].getSecondThrow();
				}
			}
		}
		cout << "\t"; //��� ���� ����
	}
	cout << endl;


	for (int i = 0; i < 10; i++) { //�� �������� ������ ���
		cout <<"\t"<< a[i].getScore() ; //Bowling���� ��ӹ��� �Լ��� ���
	}
}

void Player::showTotalFrame() { //������ ���� �� ������ ������ ���·� �����ִ� �Լ�
	showScore(); //������ ������ �Լ��� ��� �������� ���� ���
	int total = 0; 
	for (int i = 0; i < 10; i++) {
		total =total+ a[i].getScore(); //�����ӿ� ���� ���� 
	}
	cout <<"\t"<< total << endl; //���� ���
}
