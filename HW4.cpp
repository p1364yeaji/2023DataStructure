#include <iostream>
#include <cstdlib>
using namespace std;
const int MAX_QUEUE_SIZE = 50; //ť�� �ִ� ������

inline void error(string str) {
	cout << str << endl;
	exit(1);
};

//���л� �̸� ����ü
struct FemaleStudent {
	string name;
	FemaleStudent(string n = " ") : name(n) { }
};

//���л� �̸� ����ü
struct MaleStudent {
	string	name;
	MaleStudent(string n = " ") : name(n) { }
};

//(2) ���л� ť
class FemaleStudentQueue {
protected:
	int		front;
	int		rear;
	FemaleStudent data[MAX_QUEUE_SIZE];

public:
	FemaleStudentQueue() { front = 0;  rear = 0; } //������

	bool isEmpty() { return front == rear; }
	bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; }

	//������ ����
	void enqueue(FemaleStudent& val) {
		if (isFull())
			error("��ȭ ���� ����");
		else {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = val;
		}
	}
	//���� ���� ������ �����͸� ���� ��ȯ
	FemaleStudent& dequeue() {
		if (isEmpty())
			error("���� ���� ����");
		else {
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}
	//���� ���� ������ �����͸� ���� �ʰ� ���� ��ȯ
	FemaleStudent& peek() {
		if (isEmpty())
			error("���� ���� ����");
		else
			return data[(front + 1) % MAX_QUEUE_SIZE];
	}
};

//(2) ���л� ť
class MaleStudentQueue {
protected:
	int		front;
	int		rear;
	MaleStudent data[MAX_QUEUE_SIZE];

public:
	MaleStudentQueue() {front = 0;  rear = 0; } //������

	bool isEmpty() { return front == rear; }
	bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; }

	//������ ����
	void enqueue(MaleStudent& val) {
		if (isFull())
			error("��ȭ ���� ����");
		else {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = val;
		}
	}
	//���� ���� ������ �����͸� ���� ��ȯ
	MaleStudent& dequeue() {
		if (isEmpty())
			error("���� ���� ����");
		else {
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}
	//���� ���� ������ �����͸� ���� �ʰ� ���� ��ȯ
	MaleStudent& peek() {
		if (isEmpty())
			error("���� ���� ����");
		else
			return data[(front + 1) % MAX_QUEUE_SIZE];
	}
};

//�л� ��ȣ ť
class Student {
	int front;
	int rear;
	int data[MAX_QUEUE_SIZE];

public:
	Student() { front = rear = 0; }

	bool isEmpty() { return front == rear; }
	bool isFull(){ return (rear + 1) % MAX_QUEUE_SIZE == front; }

	//������ ����
	void enqueue(int val) {
		if (isFull())
			error("��ȭ ���� ����");
		else{
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = val;
		}
	}
	//���� ���� ������ �����͸� ���� ��ȯ
	int dequeue() { 
		if (isEmpty())
			error("���� ���� ����");
		else{
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}
	//���� ���� ������ �����͸� ���� �ʰ� ���� ��ȯ
	int peek() {
		if (isEmpty())
			error("���� ���� ����");
		else
			return data[(front + 1) % MAX_QUEUE_SIZE];
	}
};

//(3) ���л� ��
class FemaleStudentDeque : public FemaleStudentQueue {
public:
	FemaleStudentDeque() { front = 0;  rear = 0; }

	void addRear(FemaleStudent& val) { enqueue(val); } //enqueue ȣ��
	FemaleStudent& deleteFront() { return dequeue(); } //dequeue ȣ��

	//���ܿ� ������ ����
	void addFront(FemaleStudent& val) {
		if (isFull())
			error("��ȭ ���� ����");
		else {
			data[front] = val;
			front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
		}
	}
	//�Ĵ��� ������ ����
	FemaleStudent& deleteRear() {
		if (isEmpty())
			error("���� ���� ����");
		else {
			rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
			return data[rear];
		}
	}
	//�Ĵ� ������ peek
	FemaleStudent& getRear() {
		if (isEmpty())
			error("���� ���� ����");
		else return data[rear];
	}
};

//(3) ���л� ��
class MaleStudentDeque : public MaleStudentQueue {
public:
	MaleStudentDeque() { front = 0;  rear = 0; }

	void addRear(MaleStudent& val) { enqueue(val); } //enqueue ȣ��
	MaleStudent& deleteFront() { return dequeue(); } //dequeue ȣ��

	//���ܿ� ������ ����
	void addFront(MaleStudent& val) {
		if (isFull())
			error("��ȭ ���� ����");
		else {
			data[front] = val;
			front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
		}
	}
	//�Ĵ��� ������ ����
	MaleStudent& deleteRear() {
		if (isEmpty())
			error("���� ���� ����");
		else {
			rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
			return data[rear];
		}
	}
	//�Ĵ� ������ peek
	MaleStudent& getRear() {
		if (isEmpty())
			error("���� ���� ����");
		else return data[rear];
	}
};

//(1)~(3) ����ڰ� �л� ������ �������� ����Ͽ� ��� Ȯ��
class Meeting {
	string nStudents;	//�л� �̸�
	char gStudents;		//�л� ����
	char answer;		//��� �ּ� ��� ����
	int num;			//�л� ���� �Է� ����
	FemaleStudentDeque female;
	MaleStudentDeque male;

public:
	Meeting() { num = 1; }; //������

	//(1) ����ڰ� �л� ������ �Է��ϴ� �������̽�
	void InsertStudent() {
		cout << "�л��̸�: ";
		cin >> nStudents;
		cout << "������ �Է��ϼ���(f or m): ";
		cin >> gStudents;
		cout << "��� �ּ� �������(y or n): ";
		cin >> answer;
		if (gStudents == 'f' && answer == 'y') {
			FemaleStudent a(nStudents);
			female.addFront(a);
		}
		else if (gStudents == 'f' && answer == 'n') {
			FemaleStudent a(nStudents);
			female.addRear(a);
		}
		else if (gStudents == 'm' && answer == 'y') {
			MaleStudent a(nStudents);
			male.addFront(a);
		}
		else if (gStudents == 'm' && answer == 'n') {
			MaleStudent a(nStudents);
			male.addRear(a);
		}
	}

	void run() {
		while (num = true) { //num���� 0(false)�� �Ǹ� �ݺ��� �ߴ�
			InsertStudent();

			//�л� �ּ�
			if (!male.isEmpty() && !female.isEmpty()) {
				MaleStudent boyfriend = male.deleteFront();
				FemaleStudent girlfriend = female.deleteFront();
				cout << "Ŀ���� ź���߽��ϴ�! " << boyfriend.name << "��(��) " << girlfriend.name << endl;
			}
			else
				cout << "���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�." << endl;
			cout << "�Է��� ����Ϸ��� 1, �Է��� �ߴ��Ϸ��� 0�� �Է��Ͻÿ�: ";
			cin >> num;
		}
	}
};

//(4) �ڵ� �ùķ��̼� ����
//�ùķ��̼� Ŭ���� ����
class MeetSimulator {
	int	maxnumber;		//�ִ� �ο�
	double probArrival; //�����ð��� ��� �л� ��
	int	clock;			//���� �ð�
	int	totalWaitTime;	//�л����� ��ٸ� �� �ð�
	int count;			//�ּ� �õ� Ƚ��
	int	coupleCount;	//�� Ŀ�� ��
	Student female, male;

	double Random()		{ return rand() / (double)RAND_MAX; }
	bool IsNewStudent() { return Random() > probArrival; }

public:
	MeetSimulator() { clock = count = coupleCount = totalWaitTime = coupleCount = 0; } //������

	//�ùķ��̼��� ���� �� �Է�/����
	void readSimulationParameters() {
		cout << "�ùķ��̼� �� �ִ� �ο� (��:30 [��]) = ";
		cin >> maxnumber;
		cout << "�����ð��� �Է� �л� �� (��: 0.5 [�л�/���� �ð�]) = ";
		cin >> probArrival;
		cout << "====================================================" << endl;
	}

	void runSimul() {
		while (clock < maxnumber) {
			clock++;
			//�л� ����
			if (IsNewStudent()) {
				int g = rand() % 2; //g = 1 �� �� ���л�, g = 0 �� �� ���л����� ����
				if (g == 1) {
					cout << clock << "�� ���л��� �����߽��ϴ�." << endl;
					male.enqueue(clock);
				}
				else {
					cout << clock << "�� ���л��� �����߽��ϴ�." << endl;
					female.enqueue(clock);
				}
			}
			else
				continue;

			//�л� �ּ�
			if ((!male.isEmpty()) && (!female.isEmpty())) {
				int M = male.dequeue();
				int F = female.dequeue();
				cout << "Ŀ���� ź���߽��ϴ�! " << M << "���� " << F << "��" << endl;
				coupleCount++;
			}
			else
				cout << "���� ����ڰ� �����ϴ�." << endl;

			// ť�� ��Ұ� �����ִ� ��� ���ð� ���
			if (!male.isEmpty()) {
				int M = male.peek();
				totalWaitTime += clock - M;
			}
			else if (!female.isEmpty()) {
				int F = female.peek();
				totalWaitTime += clock - F;
			}
			count++;
		}
	}

	void printStat() {
		cout << "=================================================" << endl;
		cout << "  ���� �ּ��� ������ Ŀ���� ��  = " << coupleCount << endl;
		cout << "  ��ü ���� �ּ� Ƚ��	= " << count << endl;
		cout << "  �ּ� ���������� ��մ��ð�  = " << (double)totalWaitTime / coupleCount << "��" << endl;

	}
};

int main() {
	int num = 0;
	cout << "���� �ּ� ���α׷��Դϴ�." << endl;
	cout << "1.����� �Է� 2.�ùķ��̼� (1 �Ǵ� 2�� �Է��Ͻÿ�): ";
	cin >> num;
	if (num == 1) {
		Meeting meet; //(1) ����� �Է�
		meet.run();
	}
	else if (num == 2) {
		MeetSimulator meet; //(4) �ùķ��̼�
		meet.readSimulationParameters();
		meet.runSimul();
		meet.printStat();
	}

	return 0;
}