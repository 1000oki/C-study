#include <iostream>
#include <string>
#include "Skyline.h"
using namespace std;

void Skyline::add(size_t l, size_t r, size_t h) { //height������ ũ��� height������ ���� ����
	if (r > height.size()) { //������ x���� height���� ũ�⺸�� ũ��
		height.resize(r); //������ x����ŭ height������ ũ�⸦ ���Ҵ����ش�.
	}
	for (size_t i = l; i != r; ++i) { //���� x������ ������ x������ h���� height[i]������ Ŭ���
		if (h > height[i]) { 
			height[i] = h;
		}
	}
}

vector<pair<size_t, size_t>> Skyline::getAsSequence() const //������ ���� ������ ���� (x,y)���� ��ǥ�� �������ִ� �Լ�
{
	vector<pair<size_t, size_t>> get;
	size_t prev = 0;  //��ġ �������� ������
	for (size_t i = 0; i != height.size(); ++i) {  
		if (height[i] != prev) { //���̰� ���� ���̿� ���� ���� ��
			get.push_back(make_pair(i, height[i])); //i�� x��, height[i]�� y������ ����
			prev = height[i]; //������ �̵�
		}
	}
	get.push_back(make_pair(height.size(), 0)); //�������� x�� height�� ũ��, y�� 0���� ����
	return get; 
}

void Skyline::printSkyline() //Skyline�� �迭 ��� �Լ�
{
	get1 = getAsSequence();
	int size = get1.size();
	for (int i = 0; i < size; i++) {
		cout << "[" << get1[i].first << "," << get1[i].second << "] ";
		if (i != get1.size() - 1) {
			cout << ",";
		}
	}
}



