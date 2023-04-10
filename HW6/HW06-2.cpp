//1. ������ ����� �ܼ� ���Ḯ��Ʈ�� ��� ������ ���� ���� ����ϴ� ���α׷�
//2. �ܼ� ���� ����Ʈ���� Ư���� �����Ͱ��� ���� ����� ������ ���

#include <iostream>
using namespace std;

#define MAX_STACK_SIZE	100

inline void error(char* str) {
	cout << stderr << "\n" << str;
	exit(1);
};

//nodeŬ����
class Node
{
	Node* link;	//���� ��带 ����Ű�� ������ ����
	int	data;	//����� ������ �ʵ�

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

	//�ڽ��� ������ ���ο� ��� n�� �����ϴ� ����Լ�
	void insertNext(Node* n) {
		if (n != NULL) {
			n->link = link;
			link = n;
		}
	}

	//�ڽ��� ���� ��带 ����Ʈ�� �����ϴ� ����Լ�
	Node* removeNext() {
		Node* removed = link;
		if (removed != NULL)
			link = removed->link;
		return removed;
	}
};

//���Ḯ��Ʈ Ŭ����
class LinkedList
{
	Node org;	// ��� ��� (��� �����Ͱ� �ƴ�)

public:
	LinkedList() : org(0) { }	//������
	~LinkedList() { clear(); }	//�Ҹ���

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

	//pos��° �׸� ��ȯ
	Node* getEntry(int pos) {
		Node* n = &org;
		for (int i = -1; i < pos; i++, n = n->getLink())
			if (n == NULL)
				break;
		return n;
	}

	//��ġ�� �׸� ����
	void insert(int pos, Node* n) {
		Node* prev = getEntry(pos - 1);
		if (prev != NULL)
			prev->insertNext(n);
	}

	//��ġ�� �׸� ����
	Node* remove(int pos) {
		Node* prev = getEntry(pos - 1);
		return prev->removeNext();
	}

	//Ž�� �Լ�. val�����͸� ���� ����� �ּҸ� ��ȯ
	Node* find(int val) {
		for (Node* p = getHead(); p != NULL; p = p->getLink())
			if (p->hasData(val))
				return p;
		return NULL;
	}

	//����Ʈ�� pos��° ��带 �ٸ� ���� ��ü
	void replace(int pos, Node* n) {
		Node* prev = getEntry(pos - 1);
		if (prev != NULL) {
			delete prev->removeNext();
			prev->insertNext(n);
		}
	}

	//����Ʈ�� �׸� ���� ��ȯ
	int size() {
		int count = 0;
		for (Node* p = getHead(); p != NULL; p = p->getLink())
			count++;
		return count;
	}

	//2. Ư���� ������ ���� ���� ����� ���� ��ȯ//
	int select(int val) {
		int valCount = 0;
		for (Node* p = getHead(); p != NULL; p = p->getLink()) {
			if (p->hasData(val))
				valCount++;
		}
		return valCount;
	}

	//ȭ�鿡 ��ü ����Ʈ ����
	void display() {
		cout << "[�ܼ� ���� ����Ʈ �׸� �� = " << size() << "] : " << endl;
		for (Node* p = getHead(); p != NULL; p = p->getLink())
			p->display();
		cout << endl;
	}

	//1. ����Ʈ�� �����͸� ���Ͽ� ���//
	void displaySum() {
		int sum = 0;	//�����͵��� ���� �����ϴ� ����
		for (Node* p = getHead(); p != NULL; p = p->getLink())
			sum += p->getData();
		cout << "��� �������� ��: " << sum << endl;
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

	cout << "������ Ȯ���� �����͸� �Է��Ͻÿ�: ";
	cin >> d;
	if (list.select(d))
		cout << d << "�����͸� ���� ����� ����: " << list.select(d) << endl;
	else
		cout << d << "�� �����ͷ� ���� ���� �������� �ʽ��ϴ�." << endl;

	return 0;
}