#include <iostream>
#include <string>
#include "PlayGame.h"
#include "Bowling.h"
#include "Frame.h"
#include "Player.h"


using namespace std;

void PlayGame::gameStart(){ //게임 출력함수
	cout << "볼링게임을 시작합니다. 플레이어는 몇 명입니까?";
	cin >> numberOfPlayer;
	string name[2];
	for (int i = 0; i < numberOfPlayer; i++) {	//numberOfPlayer만큼 플레이어 이름 입력받기
		cout << "\n"<<i+1<<"번째 플레이어의 이름은 ? ";
		cin >> name[i];	//name[i]에 이름 입력받음
		p[i].setName(name[i]); //Player클래스의 setName을 통해 p[i]의 이름 정의 
	}

	cout << "\n\nWelcome to Sookmyung Bowling Club!!\n Let's start a Bowling Game!!\n";
	for (int j = 0; j < 10; j++) {	
		p[0].setnumber(j);	//플레이어 1,2가 setnumber을 통해 번갈아 가며 볼링할 수 있도록 함.
		p[1].setnumber(j);
		for (int i = 0; i < numberOfPlayer; i++) {
				cout << "\n" << p[i].getName() << "님의 "; 
				if (i == 0) {	
					p[i].printData();
				}
				else {
					p[i].printData();
			}
		}
	}

	p[0].calculateScore(); // 각 플레이어의 점수 계산
	p[1].calculateScore();
	
	cout << "\n이름\t";     //마지막 최종 프레임 출력
	for (int i = 0; i < 10; i++) {
		cout << i+1 << "\t";
	}
	cout << "합계" << endl;
	cout << p[0].getName()<<"\t";
	p[0].showTotalFrame();
	cout << "\n" << p[1].getName() << "\t";
	p[1].showTotalFrame();

}