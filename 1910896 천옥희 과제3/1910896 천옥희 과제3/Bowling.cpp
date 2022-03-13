#include <iostream>
#include <string>
#include "Bowling.h"
using namespace std;

void Bowling::calculateScore() { //�� �������� ���� ���
    for (int i = 0; i < 10; i++) {
        int score;  //�� �������� ���� �������� ����
        if (a[i].isSpare()) { //������� ���
            if (i < 9) { //10��° �����Ӻ��� ���� ��
                if (a[i + 1].isStrike()) { //���� �������� ��Ʈ����ũ �̸�
                    score = 20;  //�������� ������ 20
                }
                else { //���� �������� ��Ʈ����ũ�� �ƴϸ�
                    score = 10 + a[i + 1].getFirstThrow(); //�������� ������ 10+���� �������� ù��° ����
                }
            }
            else {  //10��° �������� ��
                score = 10 + a[i].getThirdThrow();  //10+10��° �������� ����° ����
            }
        }
        else if (a[i].isStrike()) { //��Ʈ����ũ �� ��
            if (i < 8) { //9��° �����Ӻ��� ���� ��
                if (a[i + 1].isStrike() && a[i + 2].isStrike()) { //���� �������� ��Ʈ����Ʈ�̰�, �� ���� �����ӵ� ��Ʈ����ũ �϶�
                    score = 30;  // �������� ������ 30
                }
                else if (a[i + 1].isStrike()) { //���� �������� ��Ʈ����ũ�� ��
                    score = 20 + a[i + 2].getFirstThrow(); //�������� ������ 20 + �ٴ��� �������� ù��° ���� 
                }
                else if (a[i + 1].isSpare()) { //���� �������� ����� �� ��
                    score = 20; //�������� ������ 20
                }
                else { //������������ ��Ʈ����ũ, ���� �ƴ� ��
                    score = 10 + a[i + 1].getFirstThrow() + a[i + 1].getSecondThrow(); //10 + ���� �������� ù��° ���� + ���� �������� �ι�° ����
                }
            }
            else if (i == 8) { // 9��° �������� ��
                if (a[i + 1].isStrike() && a[i + 1].getSecondThrow() == 10) { //10��° �������� ��Ʈ����ũ�̰�, 10��° �������� ����° ������ 10�� ��
                    score = 30; // �������� ������ 30
                }
                else if (a[i + 1].isStrike()) { // 10��° �������� ��Ʈ����ũ�� ��
                    score = 20 + a[i + 1].getSecondThrow(); //�������� ������ 20 + 10��° �������� ����° ����
                }
                else if (a[i + 1].isSpare()) { // 10��° �������� ������� ��
                    score = 20; //�������� ������ 20
                }
                else { //10��° �������� ��Ʈ����ũ, ���� �ƴ� ��
                    score = 10 + a[i + 1].getFirstThrow() + a[i + 1].getSecondThrow(); //�������� ������ 10 + 10��° �������� ù��° ����+10��° �������� �ι�° ����
                }
            }
            else { //10��° �������� ��
                if (a[9].getSecondThrow() == 10 && a[9].getThirdThrow() == 10) { //�ι�° ������ ����° ������ ��� 10�� ��
                    score = 30; //�������� ������ 30
                }
                else if (a[9].getSecondThrow() == 10) { //�ι�° ������ 10�� ��
                    score = 20 + a[9].getThirdThrow(); //�������� ������ 20+����° ����
                } 
                else { //�ι�° ������ 10�� �ƴ� ��
                    score = 10 + a[9].getSecondThrow() + a[9].getThirdThrow(); //�������� ������ 10 + �ι�° ���� + ����° ����
                }
            }
        }
        else { //������ ��Ʈ����ũ�� �ƴ� ��
            score = a[i].getFirstThrow() + a[i].getSecondThrow(); //�������� ������ �� �������� ù��° ���� + �� �������� �ι�° ����
        }
        a[i].setScore(score); //�� �������� ������ ����
    }
}


void Bowling::bowl() //��Ʈ����ũ, ����� ����
{
    for (int i = 0; i < 10; i++) {  
        if (a[i].getFirstThrow() == 10) { //�� �������� ù��° ������ 10�̸�
            a[i].setStrike(true); //�� �������� ��Ʈ����ũ
        }
        else { //�� �������� ù��° ������ 10�� �ƴϸ�
            a[i].setStrike(false); //�� �������� ��Ʈ����ũ�� �ƴ�
            if (a[i].getFirstThrow() + a[i].getSecondThrow() == 10) { //�� �������� ù��° ����+�ι�° ������ 10�̸�
                a[i].setSpare(true); //�� �������� �����
            }
        }
    }
}

void Bowling::printData()   //�� �������� ���� ���
{
    for (int i = 0; i < 10; i++) { //10�� �ݺ�
        if (getnumber() == i) { //getnumber�� i�� ���� ���� ��µ� �� �յ��� ��.(�÷��̾� �θ��� ������ ��µ� �� �ֵ��� �ϱ� ����)
            if (i < 9) { //10�� �����Ӻ��� ���� �� 
                int first; 
                cout << i + 1 << "�� ������ 1�� ������? "; 
                cin >> first; cout << "\n"; //ù��° ������ first�� ����
                a[i].setFirstThrow(first);  //first�� �Է� ���� ������ Frame�� setFirstThrow�Լ��� �̿��� �� �������� ù��° ������ ���� 
                bowl(); //���� isStrike�� ����ϱ� ���� strike�� spare�� �������� bowl()�Լ� ����

                if (!a[i].isStrike()) { //�������� ��Ʈ����ũ�� �ƴϸ�
                    int second; 
                    cout << i + 1 << "�� ������ 2�� ������? "; 
                    cin >> second;  cout << "\n"; //�ι�° ������ second�� �Է¹���
                    a[i].setSecondThrow(second); //second�� �Է� ���� ������ Frame�� setSecondThrow�Լ��� �̿��� �� �������� �ι�° ������ ���� 
                    bowl(); //���� isStrike�� ����ϱ� ���� strike�� spare�� �������� bowl()�Լ� ����
                }

                if (a[i].isStrike()) { //�������� ��Ʈ����ũ�̸�
                    cout << "��Ʈ����ũ! �����մϴ�."; //���� ���
                }
                else if (a[i].isSpare()) { //�������� ������̸�
                    cout << "�� ġ�̾��. ���̺긦 �ϼ̽��ϴ�."; //���� ���
                }
                else { //��Ʈ����ũ, ���� �ƴϸ�
                    cout << "�ƽ��׿�. ������ �� ġ����!"; //���� ���
                }
                cout << endl;
            }
            else if (i == 9) { //10�� ������ �� ��
                int first;
                cout << i + 1 << "�� ������ 1�� ������? ";
                cin >> first; cout << "\n";  //ù��° ������ first�� ����
                a[i].setFirstThrow(first); //first�� �Է� ���� ������ Frame�� setFirstThrow�Լ��� �̿��� �� �������� ù��° ������ ���� 

                int second;
                cout << i + 1 << "�� ������ 2�� ������? ";
                cin >> second;  cout << "\n";   //�ι�° ������ second�� �Է¹���
                a[i].setSecondThrow(second);    //second�� �Է� ���� ������ Frame�� setSecondThrow�Լ��� �̿��� �� �������� �ι�° ������ ����

                bowl(); //���� isStrike�� isSpare�� ����ϱ� ���� strike�� spare�� �������� bowl()�Լ� ����
                if (a[i].isStrike() || a[i].isSpare()) {    //��Ʈ����ũ �Ǵ� ������� ��
                    int third;
                    cout << i + 1 << "�� ������ 3�� ������? ";
                    cin >> third; cout << "\n"; //����° ������ third�� �Է¹���
                    a[i].setThirdThrow(third);  //third�� �Է� ���� ������ Frame�� setThirdThrow�Լ��� �̿��� �� �������� ����° ������ ����
                    if (a[i].getThirdThrow() == 10) //����° ������ 10�̸�
                        cout << "��Ʈ����ũ! �����մϴ�."; //���� ���
                    else //����° ������ 10�� �ƴϸ�
                        cout << "�� ġ�̾��. ���̺긦 �ϼ̽��ϴ�."; //���� ���
                }
            }
        }
    }
}

