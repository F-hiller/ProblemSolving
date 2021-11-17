[2665번: 미로만들기](https://www.acmicpc.net/problem/2665)

## 사고의 흐름

bfs문제이다. 

다만 어떤 길로 오는지에 따라 해당 정점에서의 최소의 수가 바뀌므로 visited를 bool형이 아닌 int 형으로 바꾸어서 최선의 값이 올 때마다 갱신해주는 방식을 사용했다.

ex)

111

100

100

101

이라고 할 때 (0, 0)→(0, 1)→(1, 1)→(2, 1)→(3, 1)로 오는 경우 (3, 1)까지 바꿔야하는 방의 갯수는 3개다.

하지만 (0, 0)→(1, 0)→(2, 0)→(3, 0)→(3, 1)로 온다면 1개의 방만 바꾸어도 가능하다. 이 때 bool형 visited로 전자의 경로를 먼저 기록해버리면 최선의 경로가 답으로 나올 수 없다.

```cpp
typedef pair<pii, int> piii;

int t, n, m, input1, input2;
string arr[51];
int visited[51][51];
void bfs() {
	queue<piii> q;
	q.push(piii(pii(0, 0), 0));
	while (!q.empty())
	{
		piii top = q.front();
		q.pop();
		int topY = top.first.first;
		int topX = top.first.second;
		int value = top.second;
		if ((-1 < topY&&topY < n&&-1 < topX&&topX < n) && visited[topY][topX] > value)
		{
			visited[topY][topX] = value;
			if (arr[topY][topX] == '0')
			{
				value++;
			}
			q.push(piii(pii(topY + 1, topX), value));
			q.push(piii(pii(topY - 1, topX), value));
			q.push(piii(pii(topY, topX + 1), value));
			q.push(piii(pii(topY, topX - 1), value));
		}
	}

}
int main() {
	//init
	FastIO;
	int i, j, k;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			visited[i][j] = 987654321;
		}
	}

	bfs();

	cout << visited[n - 1][n - 1];

	return 0;
}
```
