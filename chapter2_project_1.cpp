#include <iostream>
using namespace std;
#define MAX_DEGREE 80

class Polynomial {
	int		degree; //�ְ� ����
	float	coef[MAX_DEGREE]; //��� ���� ���
public:
	Polynomial() { degree = 0; } //������. �ְ� ������ 0���� �ʱ�ȭ.
	Polynomial(int num) { degree = num; } //������. �ְ� ������ num���� �ʱ�ȭ.

	//���׽��� ������ �Է¹޴� �Լ�
	void read() {
		cout << "���׽��� �ְ� ������ �Է��Ͻÿ�: ";
		cin >> degree;
		cout << "�� ���� ����� �Է��Ͻÿ� (�� " << degree + 1 << "��): ";
		for (int i = 0; i <= degree; i++)
			cin >> coef[i];
	}

	//���׽��� ������ ȭ�鿡 ����ϴ� �Լ�
	//(4)����� 0�� �� ��ü, ����� 1�� ��� ����� ��µ��� �ʵ��� ����
	void display(string str = " Poly = ") { //�Ű躯���� ����Ʈ�� ����.
		cout << fixed;
		cout.precision(1);
		cout << str;
		for (int i = 0; i < degree; i++) {
			if (coef[i] == 0.0)
				continue;											//����� 0�� ��� ������� ����
			if (coef[i + 1] >= 0)
				cout << coef[i] << " x^" << degree - i << " +  ";	//i - 1�� ����� ��ȣ�� ����� ��� +�� �Բ� ���
			else if (coef[i] == 1.0)					
				cout << " x^" << degree - i << " +  ";				//����� 1�̸� ����� ������� ����
			else
				cout << coef[i] << " x^" << degree - i << "  ";		//i - 1�� ����� ��ȣ�� ������ ��� -�� �Բ� ���
		}
		cout << coef[degree] << endl;
	}

	//���׽� a�� b�� ���ϴ� �Լ�. a�� b�� ���� �ڽ��� ���׽� ����
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
	//�ְ������� 0���� �Ǻ�
	bool isZero() { return degree == 0; }
	//��� ����� ��ȣ�� �ٲٴ� �Լ�
	void negate() {
		for (int i = 0; i <= degree; i++)
			coef[i] = -coef[i];
	}

	//���α׷��� ������Ʈ1 �߰� ����Լ�
	//(1) �� ���׽� a�� b�� ������ ���ϴ� �Լ�
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
	//(2) �� ���׽��� ������ ���ϴ� �Լ�. 
	void mult(Polynomial a, Polynomial b) {
		int Degree = a.degree + b.degree;
		int sum[MAX_DEGREE];					//���ο� �迭 ����
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
	//(3) ���� ���� �ְ����� ����� 0�� �ƴ� ���� �������� �����ϴ� �Լ�
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