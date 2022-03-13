#ifndef DRAW_H
#define DRAW_H

#include <string>
#include <vector>
using namespace std;

class Draw { //�׷��� �׸��� Ŭ����
	int max_w; //�׷������ �� ���α��̸� ������ x��ǥ �� ���� ū ������ ���ϱ� ���� �ʿ��� ����
	int max_h; //�׷������ �� ���α��̸� y��ǥ �� ���� ū ������ ���ϱ� ���� �ʿ��� ����
	char arrgraph[255][255]; //�ǹ��� �׷����� ǥ���ϱ� ���� ����
	char arrline[255][255];  //�ǹ��� ������ �׷����� ǥ���ϱ� ���� ����
	vector<size_t> le; //����(l) x��ǥ�� �������� ����
	vector<size_t> ri; //������(r) x��ǥ�� �������� ����
	vector<size_t> he; //����(h) y��ǥ�� �������� ����

public:
	void addgraph(size_t l, size_t r, size_t h); //�Էµ� ��ǥ�� ������ ���Ϳ� ��������ִ� ����Լ�
	vector<tuple<size_t, size_t, size_t>> getAslrh() const; //�Էµ� ��ǥ�� (l,r,h)������ ���Ϳ� �������ִ� ����Լ�
	void graph(vector<tuple<size_t, size_t, size_t>> lrh); //�ǹ��� �׷����� �׷��ִ� ����Լ�
	void printgraph(); //�ǹ� �׷����� ������ִ� ����Լ�
	void length(vector<pair<size_t, size_t> > length_width); //�ǹ��� ���� �׷����� �׷��ִ� ����Լ�
	void printl_w(); //�ǹ��� ���� �׷����� ������ִ� ����Լ�
};
#endif