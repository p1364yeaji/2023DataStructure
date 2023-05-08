## 2023DataStructure

* search 함수

```C++
BinaryNode* BinSrchTree::search(BinaryNode* n, int key){
	if (n == NULL)	// n이 null이면 null반환
		return NULL;
	if (key == n->getData())	//key와 노드n에서의 data가 같으면 n반환.
		return n;
	else if (key < n->getData())	//key가 n에서의 data보다 작으면 현재 노드의 왼쪽 노드를 탐색
		return search(n->getLeft(), key);
	else if (key > n->getData())	//key가 n에서의 data보다 크면 현재 노드의 오른쪽 노드를 탐색
		return search(n->getRight(), key);
};
```

* getHeight 함수
