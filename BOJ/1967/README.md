[1967번: 트리의 지름](https://www.acmicpc.net/problem/1967)

## 사고의 흐름

무방향 그래프에서 가장 가중치가 높은 경로를 찾는 문제이다. 처음에는 무방향 그래프의 표현을 int arr[10001][10001]로 설정하려고 했다. 하지만 메모리 제한에 걸려서 이를 포인터로 구현하여 코드가 조금 길어졌다. 

트리의 모든 잎 노드에서 bfs를 진행하여 가장 높은 가중치를 가지면 그것을 정답으로 저장해두는 방식으로 진행하였다.

메모리, 시간 제한은 문제만 제대로 읽으면 실수해서는 안되는 영역이라고 생각한다. 문제를 확실히 이해하고 풀이 방법에 대해 생각해보자.

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
	addNode2 = (nodePointer)malloc(sizeof(struct node));

	addNode1->next = edge[fir]->next;
	addNode1->node_num = sec;
	addNode1->value = value;

	addNode2->next = edge[sec]->next;
	addNode2->node_num = fir;
	addNode2->value = value;

	edge[fir]->next = addNode1;
	edge[sec]->next = addNode2;
}

int n, m, t, N, K, itemp1, itemp2, itemp3;
int counter[SHARING];
bool visited[SHARING];
int result = 0;

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
	for (i = 1; i <= n; i++)
	{
		if (counter[i] == 1)
		{
			bfs(i);
			clear();
		}
	}
}

int main() {
	//init
	FastIO;
	//init
	int i, j, k;
	init();

	solution();

	cout << result;

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
	for (i = 1; i < n; i++)
	{
		cin >> itemp1 >> itemp2 >> itemp3;
		push(itemp1, itemp2, itemp3);
		counter[itemp1]++;
		counter[itemp2]++;
	}
}
```
