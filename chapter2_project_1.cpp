#include <iostream>
using namespace std;
#define MAX_DEGREE 80

class Polynomial {
	int		degree; //최고 차수
	float	coef[MAX_DEGREE]; //모든 항의 계수
public:
	Polynomial() { degree = 0; } //생성자. 최고 차수를 0으로 초기화.
	Polynomial(int num) { degree = num; } //생성자. 최고 차수를 num으로 초기화.

	//다항식의 내용을 입력받는 함수
	void read() {
		cout << "다항식의 최고 차수를 입력하시오: ";
		cin >> degree;
		cout << "각 항의 계수를 입력하시오 (총 " << degree + 1 << "개): ";
		for (int i = 0; i <= degree; i++)
			cin >> coef[i];
	}

	//다항식의 내용을 화면에 출력하는 함수
	//(4)계수가 0인 항 전체, 계수가 1인 경우 계수가 출력되지 않도록 변경
	void display(string str = " Poly = ") { //매계변수의 디폴트값 지정.
		cout << fixed;
		cout.precision(1);
		cout << str;
		for (int i = 0; i < degree; i++) {
			if (coef[i] == 0.0)
				continue;											//계수가 0인 경우 출력하지 않음
			if (coef[i + 1] >= 0)
				cout << coef[i] << " x^" << degree - i << " +  ";	//i - 1항 계수의 부호가 양수인 경우 +를 함께 출력
			else if (coef[i] == 1.0)					
				cout << " x^" << degree - i << " +  ";				//계수가 1이면 계수를 출력하지 않음
			else
				cout << coef[i] << " x^" << degree - i << "  ";		//i - 1항 계수의 부호가 음수인 경우 -를 함께 출력
		}
		cout << coef[degree] << endl;
	}

	//다항식 a와 b를 더하는 함수. a와 b를 더해 자신의 다항식 설정
	void add(Polynomial a, Polynomial b) {
		if (a.degree > b.degree) {
			*this = a;
			for (int i = 0; i <= b.degree; i++)
				coef[i + (degree - b.degree)] += b.coef[i];
		}
		else {
			*this = b;
			for (int i = 0; i <= a.degree; i++)
				coef[i + (degree - a.degree)] += a.coef[i];
		}
		trim();
	}
	//최고차수가 0인지 판별
	bool isZero() { return degree == 0; }
	//모든 계수의 부호를 바꾸는 함수
	void negate() {
		for (int i = 0; i <= degree; i++)
			coef[i] = -coef[i];
	}

	//프로그래밍 프로젝트1 추가 멤버함수
	//(1) 두 다항식 a와 b의 뺄셈을 구하는 함수
	void sub(Polynomial a, Polynomial b) {
		*this = a;
		for (int i = 0; i <= b.degree; i++) {
			if (coef[degree - i] >= b.coef[b.degree - i])
				coef[degree - i] -= b.coef[b.degree - i];
			else if (i == 0 && coef[degree - i] < b.coef[b.degree - i])
				coef[degree - i] -= b.coef[b.degree - i];
			else {
				coef[degree - i - 1]--;
				coef[degree - i] += 10 - b.coef[b.degree - i];
			}
		}
		trim();
	}
	//(2) 두 다항식의 곱셈을 구하는 함수. 
	void mult(Polynomial a, Polynomial b) {
		int Degree = a.degree + b.degree;
		int sum[MAX_DEGREE];					//새로운 배열 선언
		for (int i = 0; i <= Degree; i++)
			sum[i] = 0;
		if (degree >= b.degree) {
			*this = a;
			for (int i = 0; i <= degree; i++) {
				for (int j = 0; j <= b.degree; j++) {
					sum[i + j] += coef[i] * b.coef[j];
				}
			}
			for (int i = 0; i <= Degree; i++)
				coef[i] = sum[i];
		}
		else {
			*this = b;
			for (int i = 0; i <= degree; i++) {
				for (int j = 0; j <= a.degree; j++) {
					sum[i + j] += coef[i] * a.coef[j];
				}
			}
			for (int i = 0; i <= Degree; i++)
				coef[i] = sum[i];
		}
	}
	//(3) 연산 이후 최고차항 계수가 0이 아닌 값이 나오도록 변경하는 함수
	void trim() {
		int count = 0;

		while (!coef[count])
			count++;
		if (count != 0) {
			int temp = degree;
			degree -= count;
			for (int i = 0; i <= degree; i++)
				coef[i] = coef[count + i];
		}
	}
};

int main() {
	Polynomial a, b, c, d, e;

	a.read();
	b.read();
	c.add(a, b);
	d.sub(a, b);
	e.mult(a, b);
	a.display("A = ");
	b.display("B = ");
	c.display("A+B = ");
	d.display("A-B = ");
	e.display("A*B = ");

	return 0;
}