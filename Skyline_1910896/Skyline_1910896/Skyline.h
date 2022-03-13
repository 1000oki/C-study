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
    void add(size_t l, size_t r, size_t h);  //height������ ũ��� height������ ���� ����
    vector<pair<size_t, size_t> > getAsSequence() const; //������ ���� ������ ���� (x,y)���� ��ǥ�� �������ִ� �Լ�
    void printSkyline();  //Skyline�� �迭 ��� �Լ�
};

#endif
