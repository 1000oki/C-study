#include <iostream>
#include <string>
#include "Bowling.h"
using namespace std;

void Bowling::calculateScore() { //각 프레임의 점수 계산
    for (int i = 0; i < 10; i++) {
        int score;  //각 프레임의 합을 저장해줄 공간
        if (a[i].isSpare()) { //스페어일 경우
            if (i < 9) { //10번째 프레임보다 작을 때
                if (a[i + 1].isStrike()) { //다음 프레임이 스트라이크 이면
                    score = 20;  //프레임의 점수는 20
                }
                else { //다음 프레임이 스트라이크가 아니면
                    score = 10 + a[i + 1].getFirstThrow(); //프레임의 점수는 10+다음 프레임의 첫번째 점수
                }
            }
            else {  //10번째 프레임일 때
                score = 10 + a[i].getThirdThrow();  //10+10번째 프레임의 세번째 점수
            }
        }
        else if (a[i].isStrike()) { //스트라이크 일 때
            if (i < 8) { //9번째 프레임보다 작을 때
                if (a[i + 1].isStrike() && a[i + 2].isStrike()) { //다음 프레임이 스트라이트이고, 그 다음 프레임도 스트라이크 일때
                    score = 30;  // 프레임의 점수는 30
                }
                else if (a[i + 1].isStrike()) { //다음 프레임이 스트라이크일 때
                    score = 20 + a[i + 2].getFirstThrow(); //프레임의 점수는 20 + 다다음 프레임의 첫번째 점수 
                }
                else if (a[i + 1].isSpare()) { //다음 프레임이 스페어 일 때
                    score = 20; //프레임의 점수는 20
                }
                else { //다음프레임이 스트라이크, 스페어가 아닐 때
                    score = 10 + a[i + 1].getFirstThrow() + a[i + 1].getSecondThrow(); //10 + 다음 프레임의 첫번째 점수 + 다음 프레임의 두번째 점수
                }
            }
            else if (i == 8) { // 9번째 프레임일 때
                if (a[i + 1].isStrike() && a[i + 1].getSecondThrow() == 10) { //10번째 프레임이 스트라이크이고, 10번째 프레임의 세번째 점수가 10일 때
                    score = 30; // 프레임의 점수는 30
                }
                else if (a[i + 1].isStrike()) { // 10번째 프레임이 스트라이크일 때
                    score = 20 + a[i + 1].getSecondThrow(); //프레임의 점수는 20 + 10번째 프레임의 세번째 점수
                }
                else if (a[i + 1].isSpare()) { // 10번째 프레임이 스페어일 때
                    score = 20; //프레임의 점수는 20
                }
                else { //10번째 프레임이 스트라이크, 스페어가 아닐 때
                    score = 10 + a[i + 1].getFirstThrow() + a[i + 1].getSecondThrow(); //프레임의 점수는 10 + 10번째 프레임의 첫번째 점수+10번째 프레임의 두번째 점수
                }
            }
            else { //10번째 프레임일 때
                if (a[9].getSecondThrow() == 10 && a[9].getThirdThrow() == 10) { //두번째 점수와 세번째 점수가 모두 10일 때
                    score = 30; //프레임의 점수는 30
                }
                else if (a[9].getSecondThrow() == 10) { //두번째 점수가 10일 때
                    score = 20 + a[9].getThirdThrow(); //프레임의 점수는 20+세번째 점수
                } 
                else { //두번째 점수가 10이 아닐 때
                    score = 10 + a[9].getSecondThrow() + a[9].getThirdThrow(); //프레임의 점수는 10 + 두번째 점수 + 세번째 점수
                }
            }
        }
        else { //스페어와 스트라이크가 아닐 때
            score = a[i].getFirstThrow() + a[i].getSecondThrow(); //프레임의 점수는 그 프레임의 첫번째 점수 + 그 프레임의 두번째 점수
        }
        a[i].setScore(score); //각 프레임의 점수를 정의
    }
}


void Bowling::bowl() //스트라이크, 스페어 정의
{
    for (int i = 0; i < 10; i++) {  
        if (a[i].getFirstThrow() == 10) { //각 프레임의 첫번째 점수가 10이면
            a[i].setStrike(true); //각 프레임은 스트라이크
        }
        else { //각 프레임의 첫번째 점수가 10이 아니면
            a[i].setStrike(false); //각 프레임은 스트라이크가 아님
            if (a[i].getFirstThrow() + a[i].getSecondThrow() == 10) { //각 프레임의 첫번째 점수+두번째 점수가 10이면
                a[i].setSpare(true); //각 프레임은 스페어
            }
        }
    }
}

void Bowling::printData()   //각 프레임의 점수 출력
{
    for (int i = 0; i < 10; i++) { //10번 반복
        if (getnumber() == i) { //getnumber가 i와 같을 때만 출력될 수 잇도록 함.(플레이어 두명이 번갈아 출력될 수 있도록 하기 위함)
            if (i < 9) { //10번 프레임보다 작을 때 
                int first; 
                cout << i + 1 << "번 프레임 1번 점수는? "; 
                cin >> first; cout << "\n"; //첫번째 점수를 first에 받음
                a[i].setFirstThrow(first);  //first에 입력 받은 점수를 Frame의 setFirstThrow함수를 이용해 각 프레임의 첫번째 점수로 정의 
                bowl(); //다음 isStrike를 사용하기 위해 strike와 spare를 정의해준 bowl()함수 실행

                if (!a[i].isStrike()) { //프레임이 스트라이크가 아니면
                    int second; 
                    cout << i + 1 << "번 프레임 2번 점수는? "; 
                    cin >> second;  cout << "\n"; //두번째 점수를 second에 입력받음
                    a[i].setSecondThrow(second); //second에 입력 받은 점수를 Frame의 setSecondThrow함수를 이용해 각 프레임의 두번째 점수로 정의 
                    bowl(); //다음 isStrike를 사용하기 위해 strike와 spare를 정의해준 bowl()함수 실행
                }

                if (a[i].isStrike()) { //프레임이 스트라이크이면
                    cout << "스트라이크! 축하합니다."; //문구 출력
                }
                else if (a[i].isSpare()) { //프레임이 스페어이면
                    cout << "잘 치셨어요. 세이브를 하셨습니다."; //문구 출력
                }
                else { //스트라이크, 스페어가 아니면
                    cout << "아쉽네요. 다음엔 잘 치세요!"; //문구 출력
                }
                cout << endl;
            }
            else if (i == 9) { //10번 프레임 일 때
                int first;
                cout << i + 1 << "번 프레임 1번 점수는? ";
                cin >> first; cout << "\n";  //첫번째 점수를 first에 받음
                a[i].setFirstThrow(first); //first에 입력 받은 점수를 Frame의 setFirstThrow함수를 이용해 각 프레임의 첫번째 점수로 정의 

                int second;
                cout << i + 1 << "번 프레임 2번 점수는? ";
                cin >> second;  cout << "\n";   //두번째 점수를 second에 입력받음
                a[i].setSecondThrow(second);    //second에 입력 받은 점수를 Frame의 setSecondThrow함수를 이용해 각 프레임의 두번째 점수로 정의

                bowl(); //다음 isStrike와 isSpare를 사용하기 위해 strike와 spare를 정의해준 bowl()함수 실행
                if (a[i].isStrike() || a[i].isSpare()) {    //스트라이크 또는 스페어일 때
                    int third;
                    cout << i + 1 << "번 프레임 3번 점수는? ";
                    cin >> third; cout << "\n"; //세번째 점수를 third에 입력받음
                    a[i].setThirdThrow(third);  //third에 입력 받은 점수를 Frame의 setThirdThrow함수를 이용해 각 프레임의 세번째 점수로 정의
                    if (a[i].getThirdThrow() == 10) //세번째 점수가 10이면
                        cout << "스트라이크! 축하합니다."; //문구 출력
                    else //세번째 점수가 10이 아니면
                        cout << "잘 치셨어요. 세이브를 하셨습니다."; //문구 출력
                }
            }
        }
    }
}

