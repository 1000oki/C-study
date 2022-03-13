#ifndef ARRAY_H
#define ARRAY_H

#include <string>
#include <vector>
using namespace std;

#include "Cut.h"
#include "Skyline.h"
#include "Draw.h"

class Array : public Cut, public Draw{ //��ü �迭 �� �׸� ��� Ŭ����(Cut,DrawŬ���� ���)
	Skyline sky; 
	vector<pair<size_t, size_t> > out; //Skyline�� getAsSequence()����Լ� �������� ����
public:
	void resultArray(); //��� ��� ��� ����Լ�
};

#endif