## 힙을 이용한 우선순위 큐 구현

HeapNode, MaxHeap 클래스로 우선순위 큐를 구현한 뒤, 이를 활용하여 정렬되지 않은 배열 A를 내림차순으로 정렬한다.

```C++
#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_ELEMENT = 100;


class HeapNode
{
public:
	HeapNode(int k = 0) {
		key = k;
	}
	int getKey() const {	//노드에서 키값 받아오기
		return key;
	} 
	void setKey(int k) {	//노드에 키값 저장
		key = k;
	} 
	void display() {		//노드 출력
		cout << key;
	}

private:
	int key;
};

class MaxHeap
{
	int size;	//힙 요소 개수
public:
	//초기값이 0인 생성자
	MaxHeap() {		
		size = 0;
	}

	bool isEmpty() {	//힙이 공백상태라면 true
		return size == 0;
	} 
	bool isFull() {		//힙이 포화상태라면 true
		return size == MAX_ELEMENT - 1;
	}
	HeapNode& getParent(int i) {	//부모 노드
		return node[i / 2];
	} 
	HeapNode& getLeft(int i) {		//왼쪽 자식 노드
		return node[i * 2];
	} 
	HeapNode& getRight(int i) {		//오른쪽 자식 노드
		return node[i * 2 + 1];
	}
	HeapNode find() {	//루트 노드 반환
		return node[1];
	}
	void insert(int key); //삽입 함수
	HeapNode remove(); //삭제 함수
	void display(); //힙 출력

private:
	HeapNode node[MAX_ELEMENT]; //HeapNode 객체 배열
};

// 삽입 함수 //
void MaxHeap::insert(int key)
{
	if (isFull()) //isFull() == true일 시 종료
		return;
	int i = ++size; //힙 크기를 1 증가시키고, i를 그 값으로 초기화. i는 신규 값을 삽입할 자리.

	//새 노드가 최대힙 성질을 만족하도록 조정
	while (i != 1 && key > getParent(i).getKey()) { //부모노드 보다 key가 크다면,
		node[i] = getParent(i); //부모를 자식 자리로 내리고
		i /= 2;					//한 레벨 위에서 다시 비교
	}
	node[i].setKey(key); //적합한 위치에 새로운 key값 삽입
}

// 삭제 함수 //
HeapNode MaxHeap::remove() {
	if (isEmpty()) {	//힙이 공백상태라면 에러 메세지 출력 후 종료
		cout << "empty error !" << endl; exit(-1);
	}
	HeapNode item = node[1];		//루트 노드
	HeapNode last = node[size--];	//마지막 노드
	int parent = 1; //루트 노드 인덱스
	int child = 2;	//루트의 왼쪽 자식 인덱스

	//새 루트 노드를 찾아서 정렬
	while (child <= size) {		//힙 크기 내에서
		if (child < size && getLeft(parent).getKey() < getRight(parent).getKey())	// 오른쪽 자식이 더 크면 오른쪽으로 이동
			child++; 
		if (last.getKey() >= node[child].getKey()) //부모노드가 자식 노드보다 크면 = 최대힙 성질을 만족하면 종료
			break;
		
		node[parent] = node[child]; //자식 노드보다 작으면 change
		parent = child; // 한 단계 아래 레벨로 이동
		child *= 2;
	}
	node[parent] = last; //최종 위치에 마지막 노드 저장

	return item; //삭제한 루트 노드 반환
}

// 힙 출력 함수 //
void MaxHeap::display() {
	for (int i = 1, level = 1; i < size; i++) {
		cout << " ";
		if (i == level) {
			cout << "\n" << endl;
			level *= 2;
		}
		node[i].display();
		cout << setw(3);
	}
	cout << endl << "\n------------------------\n" << endl;
}


// 메인 함수 //
void main() {

	int A[10] = {0, 10, -3, 7, 22, 33, 39, 4, -9, -5};	//정렬되지 않은 배열

	MaxHeap maxHeap;
	HeapNode Hnode;

	// 힙 출력 //
	cout << "배열 A를 정렬한 우선순위 큐" << endl;
	for (int i = 0; i < 10; i++) {
		maxHeap.insert(A[i]);
	}
	maxHeap.display();

	// 최대힙을 통해 배열 A를 정렬하여 출력 //
	cout << "내림차순으로 정렬한 배열 A: {";
	for (int i = 0; i < 10; i++) {
		Hnode = maxHeap.remove();
		A[i] = Hnode.getKey();
		if (i != 9)
			cout << A[i] << ", ";
		else
			cout << A[i];
	}

	cout << "} \n";
}
```

* 출력

