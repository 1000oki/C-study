#include <iostream>
#include <string>
#include "Player.h"
using namespace std;


void Player::showScore() { //모든 프레임의 볼링 점수보여주는 함수
	for (int i = 0; i < 10; i++) {
		if (i == 9) { // 10번째 프레임일 때
			if (a[9].isSpare() || a[9].isStrike()) { //스트라이크 또는 스페어일 때
				string score1, score2, score3;
				if (a[9].isStrike()) { //첫 번째가 스트라이크일 경우(a[i].isStrike는 Bowling에서 상속 받음)
					if (a[9].getSecondThrow() == 10) { //2번째 점수가 10일 때
						if (a[9].getThirdThrow() == 10) { //3번째 점수가 10일 때
							cout << "X X X";
						}
						else { //3번째 점수가 10이 아닐 때
							cout << "X X " << a[9].getThirdThrow();
						}
					}
					else { //첫번째가 스트라이크가 아닐 때
						if (a[9].getSecondThrow() + a[9].getThirdThrow() == 10) { //두번째 점수와 세번째 점수의 합이 10일 때
							cout << "X " << a[9].getSecondThrow() << " /";
						}
						else {	//합이 10이 아닐 때
							cout << "X " << a[9].getSecondThrow() << " " << a[9].getThirdThrow();
						}
					}
				}
				else if (a[9].isSpare()) { //스페어일 경우(a[i].isSpare는 Bowling에서 상속 받음)
					if (a[9].getThirdThrow() == 10) { //세번째 점수가 10일 때
						cout << a[9].getFirstThrow() << " / X";
					}
					else { //세번 째 점수가 10이 아닐 때
						cout << a[9].getFirstThrow() << " / " << a[9].getThirdThrow();
					}
				}
			}
			else { //스트라이크와 스페어가 아닐 경우
				cout << a[9].getFirstThrow() << " " << a[9].getSecondThrow();
			}
		}
		else {
			if (a[i].isStrike()) { //스트라이크일 경우(a[i].isStrike는 Bowling에서 상속 받음)
				cout << "X ";  //X로 출력
			}
			else {
				if (a[i].isSpare()) { //스페어일 경우(a[i].isSpare는 Bowling에서 상속 받음)
					cout << a[i].getFirstThrow() << " /";
				}
				else { //스트라이크와 스페어가 아닐 경우
					cout << a[i].getFirstThrow() << " " << a[i].getSecondThrow();
				}
			}
		}
		cout << "\t"; //출력 간격 조정
	}
	cout << endl;


	for (int i = 0; i < 10; i++) { //각 프레임의 점수를 출력
		cout <<"\t"<< a[i].getScore() ; //Bowling에서 상속받음 함수로 출력
	}
}

void Player::showTotalFrame() { //볼링의 점수 및 총합의 프레임 형태로 보여주는 함수
	showScore(); //위에서 정의한 함수로 모든 프레임의 점수 출력
	int total = 0; 
	for (int i = 0; i < 10; i++) {
		total =total+ a[i].getScore(); //프레임에 대한 총합 
	}
	cout <<"\t"<< total << endl; //총합 출력
}
