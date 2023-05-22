## 1
<img width="410" alt="DS-1" src="https://github.com/p1364yeaji/2023DataStructure/assets/126933499/0188be99-c363-4fd4-834c-6fb198ab5a9a">
<br>
<img width="410" alt="DS-1-1" src="https://github.com/p1364yeaji/2023DataStructure/assets/126933499/4149b492-825e-4a9d-a760-063ee60862f1">

-----
-----
-----


## 2
<img width="360" alt="DS-2" src="https://github.com/p1364yeaji/2023DataStructure/assets/126933499/a613b487-ccd2-42f1-85ac-9af9104cc0b3">
<br>
<img width="360" alt="DS-2-1" src="https://github.com/p1364yeaji/2023DataStructure/assets/126933499/f0f0a519-f796-4014-9a86-676d66302f26">
<br>
<img width="360" alt="DS-2-2" src="https://github.com/p1364yeaji/2023DataStructure/assets/126933499/aef3d289-319a-4e79-b5d2-f8e76a6c8226">

-----
-----
-----

## 3

* 예제 그래프

````
8
A 0 1 1 0 0 0 0 0
B 1 0 0 1 0 0 0 0 
C 1 0 0 1 1 0 0 0 
D 0 1 1 0 0 1 0 0 
E 0 0 1 0 0 0 1 1 
F 0 0 0 1 0 0 0 0 
G 0 0 0 0 1 0 0 1 
H 0 0 0 0 1 0 1 0 
````

-----

### 인접 행렬/리스트를 이용한 그래프 표현 및 탐색 가능한 프로그램 구현
모든 클래스와 메인 함수는 한 파일에서 구현했으나 분리하여 올리게 되었습니다.

- Node 클래스 + 헤더와 상수 추가

````
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int MAX_VTXS = 256;

class Node {
protected:
	int id;
	Node* link;
public:
	Node(int i, Node* l = NULL){
		id = i;
		link = l;
	}
	~Node() {
		if (link != NULL)
			delete link;
	}
	int getId() {
		return id;
	}
	Node* getLink() {
		return link;
	}
	void setId(int id) {
		this->id = id;
	}
	void setLink(Node* link) {
		this->link = link;
	}
};
````

- 그래프 표현 클래스

```
class AdjListGraph {
protected:
	int size;
	char vertices[MAX_VTXS];
	Node* adj[MAX_VTXS];
public:
	AdjListGraph() {
		size = 0;
	}
	~AdjListGraph() {
		reset();
	}

	void reset(void) {
		for (int i = 0; i < size; i++)
			if (adj[i] != NULL)
				delete adj[i];
		size = 0;
	}
	bool isEmpty() {
		return size == 0;
	}
	bool isFull() {
		return size >= MAX_VTXS;
	}
	char getVertex(int i) {
		return vertices[i];
	}
	
	void insertVertex(char val) { //정점 삽입 연산
		if (!isFull()) {
			vertices[size] = val;
			adj[size++] = NULL;
		}
		else cout << "Error: 그래프 정점 개수 초과" << endl;
	}
	void insertEdge(int u, int v) {
		adj[u] = new Node(v, adj[u]);
		adj[v] = new Node(u, adj[v]);
	}

	Node* getEdge(int u, int v) {
		if (adj[u] != NULL)
			return adj[u];
		else if (adj[v] != NULL)
			return adj[v];
		else
			return 0;
	}

	void display() {
		cout << size << endl;
		for (int i = 0; i < size; i++) {
			cout << getVertex(i) << " \n";
			for (Node* v = adj[i]; v != NULL; v = v->getLink())
				cout << "    " << getVertex(v->getId()) << endl;
			cout << endl;
		}
	}
	Node* adjacent(int v) {
		return adj[v];
	}
	void load(char* filename) {
		ifstream fp;
		fp.open(filename);
		while (!fp.eof()) {
			string tmp;
			getline(fp, tmp);
			for (int i = 0; i < tmp.length(); i++) {
				string str;
				getline(fp, str);
				insertVertex(str.at(0));
				for (int j = 0; j < tmp.length(); j++) {
					int val;
					fp >> val;
					if (val != 0)
						insertEdge(i, j);
				}
			}
			fp.close();
		}
	}
};
```


- 인접 행렬을 이용한 그래프 탐색 클래스

````
//인접 행렬을 이용한 탐색 클래스
class SrchAMGraph : public AdjListGraph {
	bool visited[MAX_VTXS];
public:
	void resetVisited() {
		for (int i = 0; i < size; i++)
			visited[i] = false;
	}
	bool isLinked(int u, int v) {
		return getEdge(u, v) != 0;
	}

	// 깊이 우선 탐색 함수
	void DFS(int v) {
		visited[v] = true;
		cout << getVertex(v) << endl;
		for (int w = 0; w < size; w++)
			if (isLinked(v, w) && visited[w] == false)
				DFS(w);
	}

	// 너비 우선 탐색 함수
#include "CircularQueue.h" //원형 큐 헤더 추가

	void BFS(int v) {
		visited[v] = true;
		cout << getVertex(v) << endl;

		CircularQueue que;
		que.enqueue(v);

		while (!que.isEmpty()) {
			int v = que.dequeue();
			for (int w = 0; w < size; w++)
				if (isLinked(v, w) && visited[w == false]) {
					visited[w] = true;
					cout << getVertex(w) << endl;
					que.enqueue(w);
				}
		}
	}
};
````

- 인접 리스트를 이용한 그래프 탐색 클래스
````
// 인접 리스트를 이용한 탐색 클래스
class SrchALGraph : public AdjListGraph {
	bool visited[MAX_VTXS];
public:
	void resetVisited() {
		for (int i = 0; i < size; i++)
			visited[i] = false;
	}
	bool isLinked(int u, int v) {
		for (Node* p = adj[u]; p != NULL; p = p->getLink())
			if (p->getId() == v)
				return true;
		return false;
	}
	// 깊이 우선 탐색 함수
	void DFS(int v) {
		visited[v] = true;
		cout << getVertex(v) << endl;
		for (Node* p = adj[v]; p != NULL; p = p->getLink())
			if (visited[p->getId()] == false)
				DFS(p->getId());
	}

	// 너비 우선 탐색 함수
#include "CircularQueue.h" //원형 큐 헤더 추가

	void BFS(int v) {
		visited[v] = true;
		cout << getVertex(v) << endl;

		CircularQueue que;
		que.enqueue(v);

		while (!que.isEmpty()) {
			int v = que.dequeue();
			for (Node* w = adj[v]; w != NULL; w = w->getLink()) {
				int id = w->getId();
				if (!visited[id]) {
					visited[id] = true;
					cout << getVertex(id) << endl;
					que.enqueue(id);
				}

			}
		}
	}
};
````

- 메인 함수

````
void main() {
	SrchAMGraph graph;
	graph.load("graph.txt");
	cout << "그래프(graph.txt)" << endl;
	graph.display();

	cout << "BFS ==> " << endl;
	graph.resetVisited();
	graph.BFS(0);
	cout << "\n";
}
````
