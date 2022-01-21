[1167번: 트리의 지름](https://www.acmicpc.net/problem/1167)

## 사고의 흐름

[BOJ 1967 - 트리의 지름](https://www.notion.so/BOJ-1967-c58fa523b0d741fda838ebb91d2239c4) 과 유사한 문제이다. 하지만 앞서 해결한 문제의 정점의 갯수가 최대 1만개였다면 이 문제에서는 최대 10만개이다.

따라서 모든 잎에서 bfs를 통해서 진행하는 방식에는 무리가 있다고 생각했고 여러 방식으로 생각해보았으나 결국 어떻게 푸는지 알아내지 못하였다. 

트리의 지름을 구하는 방식은 다음과 같다.

1. 임의의 점 x에서 가장 먼 거리에 있는 점 y를 구한다.
2. 점 y에서 가장 먼 거리에 있는 점 z를 구한다.
3. y와 z 사이의 거리가 트리의 지름이 된다.

이에 관해 증명한 내용들이 있어서 머리속에서 정리하면서 적어본다.

---

실제로 가장 긴, 지름이 되는 두 점을 u, v라고 하자.

임의의 점 x와 그에 따른 y가 있다고 할 때 발생할 수 있는 경우는 다음과 같다.

1. x가 u, v 중 하나인 경우
2. y가 u, v 중 하나인 경우
3. 둘다 u, v가 아닌 경우

1과 2의 경우 거리 관계상 y와 z가 u, v의 관계에 해당된다는 것을 알 수 있을 것이다.

3의 경우를 x와 y 경로 사이의 점 t에 따라 2개의 경우로 나눌 수 있는데 다음과 같다.

1. t가 u, v의 경로 사이에 있는 경우

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/111970d4-ebea-418c-b7fd-01cec35a88bd/Untitled.png)

x에서 가장 먼 거리가 y이므로 disatnce(t, y)가 disatnce(u, t), disatnce(t, v)들보다 크거나 같다. 하지만 disatnce(u, t) disatnce(t, v)보다 커지게 된다면 disatnce(u, v)보다 disatnce(u, y) 또는 disatnce(v, y) 사이의 거리가 더 길어지기에 disatnce(t, y) =  max( disatnce(u, t), disatnce(t, v) )라고 할 수 있다. 따라서 y에서 가장 긴 경로를 찾으면 지름이라고 할 수 있다.

1. t가 u, v의 경로 사이에 없는 경우

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/c3914784-270c-444f-bab4-bb02a2d34e11/Untitled.png)

x에서 가장 긴 경우가 y이기에 1의 길이가 3보다 길다. 따라서 u와 v의 거리보다 u와 y사이의 거리가 더 길어지므로 전제 조건인 u, v가 지름이 된다는 것이 틀리게 되므로 이 경우는 고려할 필요가 없다.

```jsx
typedef struct node* nodePointer;
typedef struct node {
	int node_num, value;
	nodePointer next;
};
nodePointer* edge;
void push(int fir, int sec, int value) {
	nodePointer addNode1, addNode2;
	addNode1 = (nodePointer)malloc(sizeof(struct node));
	//addNode2 = (nodePointer)malloc(sizeof(struct node));

	addNode1->next = edge[fir]->next;
	addNode1->node_num = sec;
	addNode1->value = value;

	//addNode2->next = edge[sec]->next;
	//addNode2->node_num = fir;
	//addNode2->value = value;

	edge[fir]->next = addNode1;
	//edge[sec]->next = addNode2;
}

int n, m, t, N, K, itemp1, itemp2, itemp3;
int counter[SHARING];
bool visited[SHARING];
int result = 0, result_node = 0;

void clear() {
	int i, j, k;
	for (i = 1; i <= n; i++)
	{
		visited[i] = 0;
	}
}

void bfs(int start) {
	int i, j, k;
	nodePointer ntemp;
	queue<pii> q;
	q.push(pii(start, 0));
	while (!q.empty())
	{
		pii top = q.front();
		q.pop();
		int index = top.first;
		int value = top.second;

		if (0 < index && index <= n && !visited[index])
		{
			if (value > result)
			{
				result = value;
				result_node = index;
			}
			visited[index] = 1;

			ntemp = edge[index]->next;
			while (ntemp)
			{
				q.push(pii(ntemp->node_num, value + ntemp->value));
				ntemp = ntemp->next;
			}
		}
	}
}

void solution() {
	int i, j, k;
	bfs(1);
	clear();
	result = 0;
	bfs(result_node);
	cout << result;
}

int main() {
	//init
	FastIO;
	//init
	int i, j, k;
	init();

	solution();

	return 0;
}

void init() {
	int i, j, k;
	cin >> n;
	edge = (nodePointer*)malloc(sizeof(nodePointer)*(n + 1));
	for (i = 1; i <= n; i++)
	{
		edge[i] = (nodePointer)malloc(sizeof(struct node));
		edge[i]->next = NULL;
	}
	for (i = 1; i <= n; i++)
	{
		cin >> itemp1;
		while (true)
		{
			cin >> itemp2;
			if (itemp2 == -1)
			{
				break;
			} 
			cin >> itemp3;
			push(itemp1, itemp2, itemp3);
			counter[itemp1]++;
		}
	}
	if (!DEBUG)
	{
		return;
	}
	nodePointer ntemp;
	cout << "=====================" << endl;
	for (i = 1; i < n; i++)
	{
		ntemp = edge[i]->next;
		cout <<"node "<< i << " : \n";
		while (ntemp)
		{
			cout << ntemp->node_num << " " << ntemp->value << endl;
			ntemp = ntemp->next;
		}
		cout << "--------------------"<< endl;
	}
	cout << "=====================" << endl;
}
```
