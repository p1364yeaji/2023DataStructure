//1. 정수가 저장된 단순 연결리스트의 모든 데이터 값을 더해 출력하는 프로그램
//2. 단순 연결 리스트에서 특정한 데이터값을 갖는 노드의 개수를 계산

#include <iostream>
using namespace std;

#define MAX_STACK_SIZE	100

inline void error(char* str) {
	cout << stderr << "\n" << str;
	exit(1);
};

//node클래스
class Node
{
	Node* link;	//다음 노드를 가리키는 포인터 변수
	int	data;	//노드의 데이터 필드

public:
	Node(int val = 0) : data(val), link(NULL) { }
	Node* getLink() {
		return link;
	}
	int getData() {
		return data;
	}
	void setLink(Node* next) {
		link = next;
	}
	void display() {
		cout << "<" << data << "> ";
	}
	bool hasData(int val) {
		return data == val;
	}

	//자신의 다음에 새로운 노드 n을 삽입하는 멤버함수
	void insertNext(Node* n) {
		if (n != NULL) {
			n->link = link;
			link = n;
		}
	}

	//자신의 다음 노드를 리스트에 삭제하는 멤버함수
	Node* removeNext() {
		Node* removed = link;
		if (removed != NULL)
			link = removed->link;
		return removed;
	}
};

//연결리스트 클래스
class LinkedList
{
	Node org;	// 헤드 노드 (헤드 포인터가 아님)

public:
	LinkedList() : org(0) { }	//생성자
	~LinkedList() { clear(); }	//소멸자

	void clear() {
		while (!isEmpty())
			delete remove(0);
	}
	Node* getHead() {
		return org.getLink();
	}
	bool isEmpty() {
		return getHead() == NULL;
	}

	//pos번째 항목 반환
	Node* getEntry(int pos) {
		Node* n = &org;
		for (int i = -1; i < pos; i++, n = n->getLink())
			if (n == NULL)
				break;
		return n;
	}

	//위치에 항목 삽입
	void insert(int pos, Node* n) {
		Node* prev = getEntry(pos - 1);
		if (prev != NULL)
			prev->insertNext(n);
	}

	//위치에 항목 삭제
	Node* remove(int pos) {
		Node* prev = getEntry(pos - 1);
		return prev->removeNext();
	}

	//탐색 함수. val데이터를 가진 노드의 주소를 반환
	Node* find(int val) {
		for (Node* p = getHead(); p != NULL; p = p->getLink())
			if (p->hasData(val))
				return p;
		return NULL;
	}

	//리스트의 pos번째 노드를 다른 노드로 교체
	void replace(int pos, Node* n) {
		Node* prev = getEntry(pos - 1);
		if (prev != NULL) {
			delete prev->removeNext();
			prev->insertNext(n);
		}
	}

	//리스트의 항목 개수 반환
	int size() {
		int count = 0;
		for (Node* p = getHead(); p != NULL; p = p->getLink())
			count++;
		return count;
	}

	//2. 특정한 데이터 값을 갖는 노드의 개수 반환//
	int select(int val) {
		int valCount = 0;
		for (Node* p = getHead(); p != NULL; p = p->getLink()) {
			if (p->hasData(val))
				valCount++;
		}
		return valCount;
	}

	//화면에 전체 리스트 츨력
	void display() {
		cout << "[단순 연결 리스트 항목 수 = " << size() << "] : " << endl;
		for (Node* p = getHead(); p != NULL; p = p->getLink())
			p->display();
		cout << endl;
	}

	//1. 리스트의 데이터를 합하여 출력//
	void displaySum() {
		int sum = 0;	//데이터들의 합을 저장하는 변수
		for (Node* p = getHead(); p != NULL; p = p->getLink())
			sum += p->getData();
		cout << "모든 데이터의 합: " << sum << endl;
	}
};

int main() {
	int d = 0;
	int nodeDate = 0;
	LinkedList list;


	for (int i = 1; i < 10; i++)
		list.insert(list.size(), new Node(i*10));

	list.display();
	list.displaySum();

	cout << "개수를 확인할 데이터를 입력하시오: ";
	cin >> d;
	if (list.select(d))
		cout << d << "데이터를 가진 노드의 개수: " << list.select(d) << endl;
	else
		cout << d << "를 데이터로 가진 노드는 존재하지 않습니다." << endl;

	return 0;
}