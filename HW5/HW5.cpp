//구간별 산천어 알의 갯수를 출력//
//출력값 오류가 있으나 수정하지 못했습니다
//추후 2차원 배열을 구현해서 문제점을 고칠 방법을 찾고, 코드를 정리할 필요가 있다고 느꼈습니다

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

//공간별 산천어 알의 개수 출력
void printMasuSalmon(int num[], const int i = Array_size);

int main() {
	stack<int> masuSalmon;
	int height[Array_size] = { 0, 3, 0, 2, 1, 0, 0, 3, 3, 1, 2 };
	int numArray[Array_size], topArray[Array_size];
	int n1 = 0, n2 = 0, k = 1; //n1은 알이 없는 중간 구간의 길이만, n2는 전체 길이
	int num1;
	
	//topArray 초기화
	for (int j = 0; j < Array_size; j++) 
		topArray[j] = 0;
			
	//Array_size만큼 반복하여 알이 남아있는 부분과 없는 부분 구분
	for (int i = 0; i < Array_size; i++) {
		//i+1번째 위치의 height가 i번째보다 낮으면 스택에 height[i]값 push
		if (height[i + 1] < height[i]) 
			masuSalmon.push(height[i]);
		else if (height[i + 1] == height[i] && !masuSalmon.empty())
			masuSalmon.push(height[i]);
		else if (height[i + 1] > height[i] && !masuSalmon.empty()) {
			masuSalmon.push(height[i]);

			
			//스택에 저장된 값을 모두 topArray에 복사
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

			//알의 개수를 계산하여 numArray에 저장
			for (int j = n1; j < n2; j++) {
				numArray[j] = (num1 - topArray[n2 - k]) * 1000;
				k++;
			}
			n1 = n2;
		}
		else if (height[i + 1] >= height[i] && masuSalmon.empty()) {
			numArray[n1] = 0; //움푹 파인 구간이 아닌 곳은 바로 numArray에 0 저장
			n1++;
			n2++;
			continue;
		}
	}

	//전체 결과 출력
	printMasuSalmon(numArray);
}

void printMasuSalmon(int num[], const int i) {
	int total = 0;

	cout << setw(35) << left << "위치" << setw(35) << "살아남은 알의 수" << endl;
	cout << "===================================================================" << endl;
	for (int j = 0; j < i; j++) {
		cout << setw(35) << left << j + 1 << setw(35) << num[j] << endl;
		total += num[j];
	}
	cout << "===================================================================" << endl;
	cout << setw(35) << left << "전체 알의 개수" << total << endl;
}