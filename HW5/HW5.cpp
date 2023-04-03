//������ ��õ�� ���� ������ ���//
//��°� ������ ������ �������� ���߽��ϴ�
//���� 2���� �迭�� �����ؼ� �������� ��ĥ ����� ã��, �ڵ带 ������ �ʿ䰡 �ִٰ� �������ϴ�

#include <iostream>
#include <iomanip>
#include <stack>
using namespace std;

const int Array_size = 11;

class Location2D {
	int row;
	int col[Array_size];
	Location2D(int r, int c[]) {
		row = r;
		for (int i = 0; i < Array_size; i++) {
			col[i] = c[i];
		}
	}

	int getRow() const {
		return row;
	}
	int getCol(int i) const {
		return col[i];
	}
	void setRow(int i) {
		row = i;
	}
};

//������ ��õ�� ���� ���� ���
void printMasuSalmon(int num[], const int i = Array_size);

int main() {
	stack<int> masuSalmon;
	int height[Array_size] = { 0, 3, 0, 2, 1, 0, 0, 3, 3, 1, 2 };
	int numArray[Array_size], topArray[Array_size];
	int n1 = 0, n2 = 0, k = 1; //n1�� ���� ���� �߰� ������ ���̸�, n2�� ��ü ����
	int num1;
	
	//topArray �ʱ�ȭ
	for (int j = 0; j < Array_size; j++) 
		topArray[j] = 0;
			
	//Array_size��ŭ �ݺ��Ͽ� ���� �����ִ� �κа� ���� �κ� ����
	for (int i = 0; i < Array_size; i++) {
		//i+1��° ��ġ�� height�� i��°���� ������ ���ÿ� height[i]�� push
		if (height[i + 1] < height[i]) 
			masuSalmon.push(height[i]);
		else if (height[i + 1] == height[i] && !masuSalmon.empty())
			masuSalmon.push(height[i]);
		else if (height[i + 1] > height[i] && !masuSalmon.empty()) {
			masuSalmon.push(height[i]);

			
			//���ÿ� ����� ���� ��� topArray�� ����
			while (masuSalmon.empty()) {
				topArray[n2] = masuSalmon.top();
				masuSalmon.pop();
				n2++;
			}
			for (int j = n1; j < n2; j++) {
				if (topArray[j] > height[i + 1]) {
					num1 = height[i + 1];
					break;
				}
				else
					num1 = topArray[n2 - 1];
			}

			//���� ������ ����Ͽ� numArray�� ����
			for (int j = n1; j < n2; j++) {
				numArray[j] = (num1 - topArray[n2 - k]) * 1000;
				k++;
			}
			n1 = n2;
		}
		else if (height[i + 1] >= height[i] && masuSalmon.empty()) {
			numArray[n1] = 0; //��ǫ ���� ������ �ƴ� ���� �ٷ� numArray�� 0 ����
			n1++;
			n2++;
			continue;
		}
	}

	//��ü ��� ���
	printMasuSalmon(numArray);
}

void printMasuSalmon(int num[], const int i) {
	int total = 0;

	cout << setw(35) << left << "��ġ" << setw(35) << "��Ƴ��� ���� ��" << endl;
	cout << "===================================================================" << endl;
	for (int j = 0; j < i; j++) {
		cout << setw(35) << left << j + 1 << setw(35) << num[j] << endl;
		total += num[j];
	}
	cout << "===================================================================" << endl;
	cout << setw(35) << left << "��ü ���� ����" << total << endl;
}