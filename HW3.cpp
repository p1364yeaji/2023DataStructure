#include <iostream>
#include <string>
using namespace std;
const int MAX_STACK_SIZE = 20;

inline void error(string message) {
	cout << message << endl;
	exit(1);
}

class OperandStack {
	int top;
	double data[MAX_STACK_SIZE];

public:
	OperandStack() { top = -1; };

	bool isEmpty() { 
		if (top == -1)
			return 1;
		else
			return 0;
	}
	bool isFull() { 
		if (top == MAX_STACK_SIZE - 1)
			return 1;
		else
			return 0;
	}

	void push(double e) {
		if (isFull())
			error("���� ��ȭ ����");
		data[++top] = e;
	}
	double pop() {
		if (isEmpty())
			error("���� ���� ����");
		return data[top--];
	}
	int getTop() {
		return top;
	}
	double getData(int n) {
		return data[n];
	}

	void display() {
		for (int i = 0; i <= top; i++)
			cout << data[i] << endl;
		cout << " ------ " << endl;
	}

	int maxStackcount(OperandStack st, double val) {
		int maxtop = 0;
		int count = 0;

		if (maxtop < st.getTop()) {
			maxtop = st.getTop();
			count = 1;
			if (st.getData(maxtop) <= val) {
				if (top != -1)
					pop();
				push(val);
			}
			else
				push(st.getData(maxtop));
		}
		else if (maxtop = st.getTop()) {
			count++;
			if (top != -1)
				pop();
			if (st.getData(maxtop) <= val)
				push(val);
			else
				push(st.getData(maxtop));
	
		}
		return count;
	}
};


double calcPostfixExpr(string str) {
	int count = 0, num = 0;
	double val;
	OperandStack st, st2, maxSt;

	for (int i = 0; i <= str.length(); i++) {
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
			count++;

			//����° �����ڸ� ó���ϱ� ���� ������ ���¸� ����
			if (count == 3) {
				int num = st.getTop();
				for (int i = 0; i <= num; i++)
					st2.push(st.getData(num - i));
				count++;
			}
			//�����ڰ� ������ ���ÿ��� 2�� pop�ؼ� ���
			double val2 = st.pop();
			double val1 = st.pop();
			switch (str[i]) {
			case '+': st.push(val1 + val2); break;
			case '-': st.push(val1 - val2); break;
			case '*': st.push(val1 * val2); break;
			case '/': st.push(val1 / val2); break; //��� ����� �ٽ� ���ÿ� push
			}
		}
		else if (str[i] >= '0' && str[i] <= '9') { //�ǿ������̸� ���ÿ� push
			val = str[i] - '0';	//���� ���ڸ� �Ǽ��� �ٲ㼭
			st.push(val);		//���ÿ� push
			num = maxSt.maxStackcount(st, val);
		}
		else
			continue;
	}
	//(1)������ �׸� ������ �ִ��� ���� �ִ밪 ��� �� ������ �׸� ������ �ִ��� ���� �� ������ ���
	cout << maxSt.pop() + 1 << "\n" << num << "\n" << " ------ " << endl;

	//����° �����ڸ� ó���ϱ� ���� ������ ���¸� ���. ����° �����ڰ� ������ empty ���.
	if (count < 3)
		cout << "empty" << endl;
	else
		st2.display();

	return (st.pop());
}

int main() {
	cout << "���� �Է�(postfix): ";
	string str;
	getline(cin, str);
	double res = calcPostfixExpr(str);
	cout << res << endl;

	
	return 0;
}