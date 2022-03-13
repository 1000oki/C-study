#include <iostream>
#include <string>
#include<stdlib.h> 
#include "Draw.h"
#include <tuple>
using namespace std;


void Draw::addgraph(size_t l, size_t r, size_t h) //�Էµ� ��ǥ�� ������ ���Ϳ� ��������ִ� ����Լ�
{
	le.push_back(l); //���� ��ǥ(l) le�����Լ��� ����
	ri.push_back(r); //������ ��ǥ(r) ri�����Լ��� ���� 
	he.push_back(h); //���� ��ǥ(h) he�����Լ��� ����
}

vector<tuple<size_t, size_t, size_t>> Draw::getAslrh() const{ //�Էµ� ��ǥ�� (l,r,h)������ ���ͷ� �������ִ� ����Լ�
	vector<tuple<size_t, size_t, size_t>>get;  
	int size = le.size();  //��ǥ�� ����
	for (int i = 0; i < size; i++) { //����, ������, ���̸� get���� ������ ����
		get.push_back(make_tuple(le[i],ri[i],he[i]));
	}
	return get; //get���� ����
}

void Draw::graph(vector<tuple<size_t, size_t, size_t>> lrh) //�ǹ��� �׷����� �׷��ִ� ����Լ�
{
	max_w = 0;  //x��ǥ�� �ִ밪 �ʱ�ȭ
	max_h = 0;  //y��ǥ�� �ִ밪 �ʱ�ȭ
	int size = lrh.size();  
	for (int i = 0; i < size; i++) { //max_w, max_h�� x��ǥ, y��ǥ�� �ִ� ���ؼ� ����
		int w = get<1>(lrh[i]);  
		int h = get<2>(lrh[i]);
		if (max_w < w) {
			max_w = get<1>(lrh[i]);
		}
		if (max_h < h) {
			max_h =  get<2>(lrh[i]);
		}
	}
	

	for (int i = max_h+5; i >= 0; i--) { //�ǹ� �׷��� �迭�� ��� ���� '.'���� �ʱ�ȭ
		for (int j = 0; j < max_w+5; j++) {
			arrgraph[i][j] = '.';
		}
	}

	for (int i = lrh.size()-1; i >= 0; i--) { //���ʿ� �ִ� �ǹ��� ���ʿ� �ִ� �ǹ��� ������, ���� �Էµ� �迭�� �������� ��ġ������ lrh���͸� ������ ���Һ��� �ݴ�� ���
		int row = get<2>(lrh[i]); //�� ������ 2���� y
		int col1 = get<0>(lrh[i]); //�� ������ 0���� ����x
		int col2 = get<1>(lrh[i]); //�� ������ 1���� ������x
		for (int j = 0; j < row+1; j++) { //�� ������ ���̸�ŭ l�� �迭�� ó��		
			arrgraph[j][col1] = 'l'; 
			arrgraph[j][col2] = 'l';

			for (int k = col1 + 1; k < col2; k++) { //���ʿ� �ִ� �ǹ��� ���ʿ� �ִ� �ǹ��� ������ ������ ���� �ǹ��� �߰� �ɶ����� ���� �ǹ� �ȿ� ���� �ǹ��� ��ġ�ϴ� �κ��� '.'�κ����� ����
				if (arrgraph[j][k] != '.') {
					arrgraph[j][k] = '.';
				}
			}
		}
		for (int j = col1 + 1; j < col2; j++) { //�� ������ ���� ����(col1���� col2����) ��ŭ '_' �迭�� ����
			if (arrgraph[row + 1][j] == 'l') { //����� ���ؼ� 'l'�� ��ġ�ߴ� �κ��� �״�� '��'�� �д�.
				arrgraph[row + 1][j] = 'l';
			}
			else {
				arrgraph[row + 1][j] = '_'; //�׷��� ���� �κи� '_'�� �迭�� ����
			}
		}
	}

	for (int j = 0; j < max_w + 5; j++) { //X���� �غκ��� ǥ���ϱ� ���� '_'�迭�� ����
		if (arrgraph[1][j] == '.') {
			arrgraph[1][j] = '_';
		}
	}
}

void Draw::printgraph() //�ǹ� �׷����� ������ִ� ����Լ�
{
	for (int i = max_h + 5; i > 0; i--) { //y���� ���̴� �ִ� y�� ���̺��� +5���� ��ŭ
		for (int j = 1; j < max_w + 5; j++) { //x���� ���̴� �ִ� x���̺��� +5���� ��ŭ
			cout << arrgraph[i][j]; //�׷��� ���
		}
		cout << "\n";
	}
}

void Draw::length(vector<pair<size_t, size_t>> length_width) //�ǹ��� ���� �׷����� �׷��ִ� ����Լ�
{
	
	for (int i = max_h + 5; i > 0; i--) { //�ǹ� ���� �׷��� �迭�� ��� ���� .���� �ʱ�ȭ
		for (int j = 0; j < max_w + 5; j++) {
			arrline[i][j]= '.';
		}
	}

	int h = length_width[0].second ; //�ǹ��� ����
	for (int i = 0; i < h+1; i++) { //ù ù��°�ǹ��� ���̸�ŭ 'l' �迭�� ����
		arrline[i][length_width[0].first] = 'l'; 
	}
	int size = length_width.size();  //length_width������ ũ��
	for (int i = 1; i <size; i++) {   //���� �׷��� ����
		int l = length_width[i].second - length_width[i - 1].second; //���� ���Ϳ��ҿ��� y��ġ ����
		int h1 = length_width[i-1].second; //���� ���Ϳ����� y��ġ
		int w = length_width[i].first; //���� ������ x��ġ
		if (l < 0) { //���� ���Ϳ��ҿ��� y��ġ ���̰� 0���� ������
			for (int j = h1; j > h1 + l; j--) { //���� ���Ϳ����� y��ġ���� ���� ���Ϳ����� y��ġ�� �������鼭 'l'�� ����
				arrline[j][w] = 'l';
			}
		}
		else { //���� ���Ϳ��ҿ��� ���̰� 0���� ũ��
			for (int j = h1 + 1; j < h1 + l + 1; j++) { //���� ���Ϳ����� y��ġ���� ���� ���Ϳ����� y��ġ�� �ø����鼭 '��'�� ����
				arrline[j][w] = 'l';
			}
		}
	}
	
	for (int i = 1; i < size; i++) { //���� �׷��� ����
		int w2 = length_width[i].first ;  
		for (int j = length_width[i-1].first+1; j < w2 ; j++) { //���� ���Ϳ����� x��ġ+1���� ���� ���Ϳ����� x��ġ���� '_'����
			arrline[length_width[i-1].second+1][j] = '_';
		}
	}
	for (int j = 0; j < max_w + 5; j++) { //X���� �غκ��� ǥ���ϱ� ���� '_'�迭�� ����
		if (arrline[1][j] =='.') {
			arrline[1][j] = '_';
		}
	}
}


void Draw::printl_w() //�ǹ��� ���� �׷����� ������ִ� ����Լ�
{
	for (int i = max_h + 5; i >0; i--) {//y���� ���̴� �ִ� y�� ���̺��� +5���� ��ŭ
		for (int j = 1; j < max_w + 5; j++) { //x���� ���̴� �ִ� x���̺��� +5���� ��ŭ
			cout<< arrline[i][j]; //�׷��� ���
		}
		cout << "\n";
	}
}
