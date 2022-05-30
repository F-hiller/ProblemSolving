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

- C++

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
