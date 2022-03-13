#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include<stdlib.h>
#include "Array.h"
#include "Cut.h"
#include "Skyline.h"
using namespace std;

void Array::resultArray() { //��� ��� ��� ����Լ�
	string text; //�Է¹��� ���ڿ� �־��� ����
	while (true) { //�������� �Է��� ���� �ʾ��� ��� �ݺ�
		cout << "�Է� : "; 
		strArr.clear(); //���� ���� �� �ٽ� �ݺ��� ���� strArr������ ���� ����
		numArr.clear(); //���� ���� �� �ٽ� �ݺ��� ���� numArr������ ���� ����
		getline(cin, text); //���ٷ� ���� �Է�
		structs(text); //CutŬ�������� ��� ���� ��� �Լ��� text�� ������ ��� l,r,h �ѹ����� ���� strArr���Ϳ� ����
		numcut(); //CutŬ�������� ��� ���� ��� �Լ��� strArr�� ������ ���ڵ��� ������� numArr�迭�� ���� ���� �� ����
		int i = 0;
		int size = numArr.size();
		int absolute = numArr[i + 1] - numArr[i]; 
		bool result = 1; //������ �����ϴ��� Ȯ��

		while (i < size) { //�Էµ� ���ڿ� ����Ȯ�� 
			if (numArr[i] <= numArr[i + 1] && numArr[i] > 0 && numArr[i + 1] <= 255 && abs(absolute) >= 1 && abs(absolute) <= 104 && numArr[i + 2] <= 255 && numArr[i + 2]) {
				result = 1;
			}
			else {
				result = 0;
				break;
			}
			i += 3;
		}

		if (result == true) { //������ �´ٸ� ���
			for (int i = 0; i < size; i += 3) { //Skyline�� addȣ���ؼ� height������ ũ��� height������ ���� ����(numArr�迭�� ������ ���� ������� ����)
				sky.add(numArr[i], numArr[i + 1], numArr[i + 2]); 
			}

			cout << "��� : ";	//��� ���
			vector<pair<size_t, size_t>> g; 
			g = sky.getAsSequence(); 
			sky.printSkyline(); //Skyline�� �迭 ��� �Լ� ȣ��

			cout << "\n\n�ǹ�\n";	//�ǹ� �׷��� ���
			for (int i = 0; i < size; i += 3) { //DrawŬ�������� ��ӹ޾� numArr�迭 ������ ���� ������ ���Ϳ� ����
				addgraph(numArr[i], numArr[i + 1], numArr[i + 2]);
			}
			vector<tuple<size_t, size_t, size_t>> s;
			s = getAslrh(); //DrawŬ�������� ��ӹ��� getAslrh()�Լ��� �Էµ� ��ǥ�� (l,r,h)������ ���Ϳ� ������ s�� ����
			graph(s); //DrawŬ�������� ��ӹ޾��� graph�Լ��� �ǹ��� �׷��� �׸�
			printgraph(); //DrawŬ�������� ��ӹ޾��� printgraph�Լ��� �׷��� ���

			cout << "\n\n�ǹ��� ����\n";
			length(g); //DrawŬ�������� ��ӹ��� length�Լ��� �ǹ��� ���� �׷��� �׸�
			printl_w(); //DrawŬ�������� ��ӹ��� printl_w�Լ��� �׷��� ���
			break; //�ݺ����� �������� ���α׷� ����
		}
		else { //������ Ʋ���� �����, �ݺ����� ���������� ���ϰ� �ٽ� ����
			cout << "���ǿ� �˸��� �ʽ��ϴ�!\n[����] \n1 <= buildings.length <= 104\n0 <= left[i] < right[i] <= 255\n1 <= height[i] <= 255\n�ٽ� �Է��Ͻʽÿ�.\n";
		}
	}
};