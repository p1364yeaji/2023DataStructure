#include <iostream>
#include <cstdlib>
using namespace std;
const int MAX_QUEUE_SIZE = 50; //큐의 최대 사이즈

inline void error(string str) {
	cout << str << endl;
	exit(1);
};

//여학생 이름 구조체
struct FemaleStudent {
	string name;
	FemaleStudent(string n = " ") : name(n) { }
};

//남학생 이름 구조체
struct MaleStudent {
	string	name;
	MaleStudent(string n = " ") : name(n) { }
};

//(2) 여학생 큐
class FemaleStudentQueue {
protected:
	int		front;
	int		rear;
	FemaleStudent data[MAX_QUEUE_SIZE];

public:
	FemaleStudentQueue() { front = 0;  rear = 0; } //생성자

	bool isEmpty() { return front == rear; }
	bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; }

	//데이터 삽입
	void enqueue(FemaleStudent& val) {
		if (isFull())
			error("포화 상태 에러");
		else {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = val;
		}
	}
	//가장 먼저 저장한 데이터를 빼서 반환
	FemaleStudent& dequeue() {
		if (isEmpty())
			error("공백 상태 에러");
		else {
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}
	//가장 먼저 저장한 데이터를 빼지 않고 값만 반환
	FemaleStudent& peek() {
		if (isEmpty())
			error("공백 상태 에러");
		else
			return data[(front + 1) % MAX_QUEUE_SIZE];
	}
};

//(2) 남학생 큐
class MaleStudentQueue {
protected:
	int		front;
	int		rear;
	MaleStudent data[MAX_QUEUE_SIZE];

public:
	MaleStudentQueue() {front = 0;  rear = 0; } //생성자

	bool isEmpty() { return front == rear; }
	bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; }

	//데이터 삽입
	void enqueue(MaleStudent& val) {
		if (isFull())
			error("포화 상태 에러");
		else {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = val;
		}
	}
	//가장 먼저 저장한 데이터를 빼서 반환
	MaleStudent& dequeue() {
		if (isEmpty())
			error("공백 상태 에러");
		else {
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}
	//가장 먼저 저장한 데이터를 빼지 않고 값만 반환
	MaleStudent& peek() {
		if (isEmpty())
			error("공백 상태 에러");
		else
			return data[(front + 1) % MAX_QUEUE_SIZE];
	}
};

//학생 번호 큐
class Student {
	int front;
	int rear;
	int data[MAX_QUEUE_SIZE];

public:
	Student() { front = rear = 0; }

	bool isEmpty() { return front == rear; }
	bool isFull(){ return (rear + 1) % MAX_QUEUE_SIZE == front; }

	//데이터 삽입
	void enqueue(int val) {
		if (isFull())
			error("포화 상태 에러");
		else{
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = val;
		}
	}
	//가장 먼저 저장한 데이터를 빼서 반환
	int dequeue() { 
		if (isEmpty())
			error("공백 상태 에러");
		else{
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}
	//가장 먼저 저장한 데이터를 빼지 않고 값만 반환
	int peek() {
		if (isEmpty())
			error("공백 상태 에러");
		else
			return data[(front + 1) % MAX_QUEUE_SIZE];
	}
};

//(3) 여학생 덱
class FemaleStudentDeque : public FemaleStudentQueue {
public:
	FemaleStudentDeque() { front = 0;  rear = 0; }

	void addRear(FemaleStudent& val) { enqueue(val); } //enqueue 호출
	FemaleStudent& deleteFront() { return dequeue(); } //dequeue 호출

	//전단에 데이터 삽입
	void addFront(FemaleStudent& val) {
		if (isFull())
			error("포화 상태 에러");
		else {
			data[front] = val;
			front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
		}
	}
	//후단의 데이터 삭제
	FemaleStudent& deleteRear() {
		if (isEmpty())
			error("공백 상태 에러");
		else {
			rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
			return data[rear];
		}
	}
	//후단 데이터 peek
	FemaleStudent& getRear() {
		if (isEmpty())
			error("공백 상태 에러");
		else return data[rear];
	}
};

//(3) 남학생 덱
class MaleStudentDeque : public MaleStudentQueue {
public:
	MaleStudentDeque() { front = 0;  rear = 0; }

	void addRear(MaleStudent& val) { enqueue(val); } //enqueue 호출
	MaleStudent& deleteFront() { return dequeue(); } //dequeue 호출

	//전단에 데이터 삽입
	void addFront(MaleStudent& val) {
		if (isFull())
			error("포화 상태 에러");
		else {
			data[front] = val;
			front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
		}
	}
	//후단의 데이터 삭제
	MaleStudent& deleteRear() {
		if (isEmpty())
			error("공백 상태 에러");
		else {
			rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
			return data[rear];
		}
	}
	//후단 데이터 peek
	MaleStudent& getRear() {
		if (isEmpty())
			error("공백 상태 에러");
		else return data[rear];
	}
};

//(1)~(3) 사용자가 학생 정보를 수동으로 등록하여 결과 확인
class Meeting {
	string nStudents;	//학생 이름
	char gStudents;		//학생 성별
	char answer;		//즉시 주선 희망 여부
	int num;			//학생 정보 입력 여부
	FemaleStudentDeque female;
	MaleStudentDeque male;

public:
	Meeting() { num = 1; }; //생성자

	//(1) 사용자가 학생 정보를 입력하는 인터페이스
	void InsertStudent() {
		cout << "학생이름: ";
		cin >> nStudents;
		cout << "성별을 입력하세요(f or m): ";
		cin >> gStudents;
		cout << "즉시 주선 희망여부(y or n): ";
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
		while (num = true) { //num값이 0(false)가 되면 반복문 중단
			InsertStudent();

			//학생 주선
			if (!male.isEmpty() && !female.isEmpty()) {
				MaleStudent boyfriend = male.deleteFront();
				FemaleStudent girlfriend = female.deleteFront();
				cout << "커플이 탄생했습니다! " << boyfriend.name << "와(과) " << girlfriend.name << endl;
			}
			else
				cout << "아직 대상자가 없습니다. 기다려주십시오." << endl;
			cout << "입력을 계속하려면 1, 입력을 중단하려면 0을 입력하시오: ";
			cin >> num;
		}
	}
};

//(4) 자동 시뮬레이션 구현
//시뮬레이션 클래스 정의
class MeetSimulator {
	int	maxnumber;		//최대 인원
	double probArrival; //단위시간당 등록 학생 수
	int	clock;			//현재 시간
	int	totalWaitTime;	//학생들이 기다린 총 시간
	int count;			//주선 시도 횟수
	int	coupleCount;	//총 커플 수
	Student female, male;

	double Random()		{ return rand() / (double)RAND_MAX; }
	bool IsNewStudent() { return Random() > probArrival; }

public:
	MeetSimulator() { clock = count = coupleCount = totalWaitTime = coupleCount = 0; } //생성자

	//시뮬레이션을 위한 값 입력/설정
	void readSimulationParameters() {
		cout << "시뮬레이션 할 최대 인원 (예:30 [명]) = ";
		cin >> maxnumber;
		cout << "단위시간당 입력 학생 수 (예: 0.5 [학생/단위 시간]) = ";
		cin >> probArrival;
		cout << "====================================================" << endl;
	}

	void runSimul() {
		while (clock < maxnumber) {
			clock++;
			//학생 생성
			if (IsNewStudent()) {
				int g = rand() % 2; //g = 1 일 때 남학생, g = 0 일 때 여학생으로 생성
				if (g == 1) {
					cout << clock << "번 남학생이 참석했습니다." << endl;
					male.enqueue(clock);
				}
				else {
					cout << clock << "번 여학생이 참석했습니다." << endl;
					female.enqueue(clock);
				}
			}
			else
				continue;

			//학생 주선
			if ((!male.isEmpty()) && (!female.isEmpty())) {
				int M = male.dequeue();
				int F = female.dequeue();
				cout << "커플이 탄생했습니다! " << M << "번과 " << F << "번" << endl;
				coupleCount++;
			}
			else
				cout << "아직 대상자가 없습니다." << endl;

			// 큐에 요소가 남아있는 경우 대기시간 계산
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
		cout << "  미팅 주선에 성공한 커플의 수  = " << coupleCount << endl;
		cout << "  전체 미팅 주선 횟수	= " << count << endl;
		cout << "  주선 성공까지의 평균대기시간  = " << (double)totalWaitTime / coupleCount << "분" << endl;

	}
};

int main() {
	int num = 0;
	cout << "미팅 주선 프로그램입니다." << endl;
	cout << "1.사용자 입력 2.시뮬레이션 (1 또는 2를 입력하시오): ";
	cin >> num;
	if (num == 1) {
		Meeting meet; //(1) 사용자 입력
		meet.run();
	}
	else if (num == 2) {
		MeetSimulator meet; //(4) 시뮬레이션
		meet.readSimulationParameters();
		meet.runSimul();
		meet.printStat();
	}

	return 0;
}