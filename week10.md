## search 함수

```C++
///BinSrchTree 클래스의 맴버 함수 search

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

## getHeight 함수




```C++
///BinaryNode클래스의 맴버함수 getHeight 오버로딩

int getHeight() {
		if (left == NULL && right == NULL) //현재 node가 최하단 노드라면 높이 1 반환
			return 1;
		else if (left == NULL && right != NULL) {	//자식 노드가 있다면 왼쪽과 오른쪽 노드 각각 탐색
			int hLeft = getHeight(left);
			int hRight = getHeight(right);
			return (hLeft > hRight) ? hLeft + 1 : hRight + 1;	//왼쪽과 오른쪽 중 값이 더 큰 쪽을 반환
		}
	};
	int getHeight(BinaryNode* node) {
		if (node == NULL)	//node = NULL이면 0반환
			return 0;
		else {
			int hLeft = getHeight(left);
			int hRight = getHeight(right);
			return (hLeft > hRight) ? hLeft + 1 : hRight + 1;
		}
	}
```
