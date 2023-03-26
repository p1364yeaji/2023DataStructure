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
			error("스택 포화 에러");
		data[++top] = e;
	}
	double pop() {
		if (isEmpty())
			error("스텍 공백 에러");
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

			//세번째 연산자를 처리하기 직전 스택의 상태를 저장
			if (count == 3) {
				int num = st.getTop();
				for (int i = 0; i <= num; i++)
					st2.push(st.getData(num - i));
				count++;
			}
			//연산자가 나오면 스택에서 2개 pop해서 계산
			double val2 = st.pop();
			double val1 = st.pop();
			switch (str[i]) {
			case '+': st.push(val1 + val2); break;
			case '-': st.push(val1 - val2); break;
			case '*': st.push(val1 * val2); break;
			case '/': st.push(val1 / val2); break; //계산 결과를 다시 스택에 push
			}
		}
		else if (str[i] >= '0' && str[i] <= '9') { //피연산자이면 스택에 push
			val = str[i] - '0';	//읽은 문자를 실수로 바꿔서
			st.push(val);		//스택에 push
			num = maxSt.maxStackcount(st, val);
		}
		else
			continue;
	}
	//(1)스택의 항목 개수가 최대일 때의 최대값 출력 및 스택의 항목 개수가 최대인 경우는 몇 번인지 출력
	cout << maxSt.pop() + 1 << "\n" << num << "\n" << " ------ " << endl;

	//세번째 연산자를 처리하기 직전 스택의 상태를 출력. 세번째 연산자가 없으면 empty 출력.
	if (count < 3)
		cout << "empty" << endl;
	else
		st2.display();

	return (st.pop());
}

int main() {
	cout << "수식 입력(postfix): ";
	string str;
	getline(cin, str);
	double res = calcPostfixExpr(str);
	cout << res << endl;

	
	return 0;
}