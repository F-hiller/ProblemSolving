## 문제

<그림 1>과 같이 정사각형 모양의 지도가 있다. 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다. 철수는 이 지도를 가지고 연결된 집의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다. 여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다. 대각선상에 집이 있는 경우는 연결된 것이 아니다. <그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다. 지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.

![https://www.acmicpc.net/upload/images/ITVH9w1Gf6eCRdThfkegBUSOKd.png](https://www.acmicpc.net/upload/images/ITVH9w1Gf6eCRdThfkegBUSOKd.png)

## 입력

첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고, 그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.

## 출력

첫 번째 줄에는 총 단지수를 출력하시오. 그리고 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.

### 사고의 흐름

그래프 탐색으로 BFS를 사용해서 풀었다.

이를 C언어로 바꿔보는 작업을 해보자.

- C로 바꾼 코드

```cpp
#define _CRT_SECURE_NO_WARNINGS
#define MAX_ELEMENTS 100100
#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int first;
	int second;
}element;
element queue[MAX_ELEMENTS];
int front = 0;
int rear = -1;

int isEmpty() {
	if (front > rear) { return 1; }
	return 0;
}
//원래는 element로 다루는게 좋을 거 같지만..
//void push(element value) {
//	queue[++rear].first = value.first;
//	queue[rear].second = value.second;
//}
void push(int value1, int value2) {
	queue[++rear].first = value1;
	queue[rear].second = value2;
}
void pop() {
	if (isEmpty()) {
		printf("pop action DENIED : queue is Empty.");
		return;
	}
	front++;
}
element frontKey() {
	if (isEmpty()) {
		printf("frontKey action DENIED : queue is Empty.");
		return ;
	}
	return queue[front];
}
int n;
char** v;
short int** visited;
int result[MAX_ELEMENTS];
int resultSize = -1;
void bfs(int i, int j) {
	push(i, j);
	int resultValue = 0;
	while (!isEmpty())
	{
		element top = frontKey();
		pop();
		int topY = top.first;
		int topX = top.second;
		if ((-1 < topY && topY < n) && (-1 < topX && topX < n) && v[topY][topX] == '1' && !visited[topY][topX])
		{
			visited[topY][topX] = 1;
			resultValue++;
			push(topY - 1, topX); //북
			push(topY, topX + 1); //동
			push(topY + 1, topX); //남
			push(topY, topX - 1); //서
		}
	}
	result[++resultSize] = resultValue;
}
void QuickSort(int data[], int left, int right) {
	int num, i, j, temp;
	if (right > left) {
		num = data[right];
		i = left - 1;
		j = right;

		for (;;) {
			while (data[++i] < num);
			while (data[--j] > num);
			if (i >= j)
				break;
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
		temp = data[i];
		data[i] = data[right];
		data[right] = temp;

		QuickSort(data, left, i - 1);
		QuickSort(data, i + 1, right);
	}
}
int main() {
	//init
	scanf("%d", &n);

	v = (char**)malloc(sizeof(char*)*n);
	for (int i = 0; i < n; i++) { 
		v[i] = (char*)malloc(sizeof(char)*(n + 1));
	}

	visited = (short int**)malloc(sizeof(short int*)*n);
	for (int i = 0; i < n; i++) { 
		visited[i] = (short int*)malloc(sizeof(short int)*n);
	}

	for (int i = 0; i < n; i++) {
		scanf("%s", v[i]);
		for (int j = 0; j < n; j++) { visited[i][j] = 0; }
	}

	//BFS
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (v[i][j] == '1' && !visited[i][j])
			{
				bfs(i, j);
			}
		}
	}
	QuickSort(result, 0, resultSize);
	printf("%d\n", ++resultSize);
	for (int i = 0; i < resultSize; i++)
	{
		printf("%d\n", result[i]);
	}

	return 0;
}
```

- C++

```cpp
int n;
vector<int> result;
vector<string> v;
vector<vector<bool>> visited;

queue<pii> q;
void bfs(int i, int j) {
	q.push(pii(i, j));
	int resultValue = 0;
	while (!q.empty())
	{
		pii top = q.front();
		q.pop();
		int topY = top.first;
		int topX = top.second;
		if ((-1 < topY && topY < n) && (-1 < topX && topX < n) && v[topY][topX] == '1' && !visited[topY][topX])
		{
			visited[topY][topX] = 1;
			resultValue++;
			q.push(pair<int, int>(topY - 1, topX)); //북
			q.push(pair<int, int>(topY, topX + 1)); //동
			q.push(pair<int, int>(topY + 1, topX)); //남
			q.push(pair<int, int>(topY, topX - 1)); //서
		}
	}
	result.push_back(resultValue);
}
int main() {
	FastIO;
	//init
	cin >> n;
	string s;
	vector<bool> visitedTemp(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		v.push_back(s);
		visited.push_back(visitedTemp);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (v[i][j] == '1' && !visited[i][j])
			{
				bfs(i, j);
			}
		}
	}

	sort(result.begin(), result.end());
	cout << result.size() << endl;
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}
	return 0;
}
```
