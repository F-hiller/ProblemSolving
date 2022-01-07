[2468번: 안전 영역](https://www.acmicpc.net/problem/2468)

## 사고의 흐름

그래프 탐색 문제였고 비가 차오르는 높이에 따라 bfs를 실행해줘야해서 3중 for문을 통해서 구현했다. 

첫번째 for문에서는 빗물이 차오르는 높이를 정해줬고 

두번째, 세번째 for문을 통해 높이에 따른 안전 영역의 갯수를 찾아줬다.

한 번 틀렸는데 빗물의 높이 h를 전역변수로 선언해서 선언할 때 값을 0으로 넣어줘서 h=0으로 시작할 줄 알았지만 첫번째 for문에서 h=1을 적어놓아서 틀렸다. 코드를 작성할 때 수정할 생각보다 정확하게 적도록 노력하자.

```cpp
int n, m, itemp1, itemp2, itemp3;
int arr[100][100];
bool visited[100][100];
int h = 0;
int result = 1, result_temp;

void solution(int y, int x) {
	int i, j, k;
	bool check = 0;
	queue<pii> q;
	q.push(pii(y, x));
	while (!q.empty())
	{
		pii top = q.front();
		q.pop();
		int topY = top.first;
		int topX = top.second;
		if (-1 < topY && topY < n && -1 < topX && topX<n && !visited[topY][topX] && arr[topY][topX] > h)
		{
			check = 1;
			visited[topY][topX] = 1;
			q.push(pii(topY + 1, topX));
			q.push(pii(topY, topX - 1));
			q.push(pii(topY - 1, topX));
			q.push(pii(topY, topX + 1));
		}
	}
	if (check)
	{
		result_temp++;
	}
}

void clear() {
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			visited[i][j] = 0;
		}
	}
}

int main() {
	//init
	FastIO;
	int i, j, k;

	//input
	init();

	for (h = 0; h < 101; h++)
	{
		result_temp = 0;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (!visited[i][j])
				{
					solution(i, j);
				}
			}
		}
		if (result < result_temp)
		{
			result = result_temp;
		}
		clear();
	}

	cout << result;

	return 0;
}
void init() {
	int i, j, k;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
}
```
