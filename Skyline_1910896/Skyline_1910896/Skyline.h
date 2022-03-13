#ifndef SKYLINE_H
#define SKYLINE_H

#include <string>
#include <vector>
using namespace std;

class Skyline {
private:
    vector<size_t> height;
    vector<pair<size_t, size_t>> get1;
public:
    Skyline() {}; 
    void add(size_t l, size_t r, size_t h);  //height벡터의 크기와 height벡터의 원소 삽입
    vector<pair<size_t, size_t> > getAsSequence() const; //높이의 값이 변했을 때의 (x,y)쌍의 좌표로 리턴해주는 함수
    void printSkyline();  //Skyline의 배열 출력 함수
};

#endif
