[16236번: 아기 상어](https://www.acmicpc.net/problem/16236)

## 사고의 흐름

매번 언젠가는 풀어야지라고 생각만하고 손은 대고 있지않았던 문제이다.

bfs를 통해 풀기는 했지만 문제를 풀 수 있는 핵심적인 생각은 스스로 도출해내지 못했다.

상어는 가장 위쪽에, 가장 왼쪽에 있는 먹이를 먹으러 움직이는데 일반적인 bfs 탐색법은 이를 만족할 수 없다. 따라서 bfs 함수 안에 while문 하나를 더 넣어줘서 bfs의 한 단계마다 먹이가 있는지 탐색하게 하였다. 즉 원래 bfs함수에서는 어떤 위치의 상하좌우에 방문할 때마다 그곳에 먹이가 있는지 탐색한 후 바로 방문하는 식이었다면, 수정된 bfs함수에서는 어떤 위치로부터 거리가 1인 먹이들을 모아놓고 가장 위쪽, 가장 왼쪽인 먹이를 찾도록 하였다.

```cpp
int t, n, m, input1, input2;
vector<vector<int>> board;
vector<vector<bool>> visited;
vector<int> vtemp;
vector<bool> visitedTemp;
pii shark;
int sharkSize = 2;
int sharkFoodCount = 0;
int resultTime = 0;

void visitedClear() {
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			visited[i][j] = 0;
		}
	}
}
void sharkEat() {
	if (++sharkFoodCount == sharkSize)
	{
		sharkFoodCount = 0;
		sharkSize++;
	}
}
pii bfs(pii ptemp) {
	queue<piii> q;
	q.push(piii(ptemp, 0));
	int count = 0;
	int nextY = n, nextX = n;
	while (!q.empty())
	{
		int checkY = nextY;
		int checkX = nextX;
		while (!q.empty() && (count == q.front().second))
		{
			piii top = q.front();
			q.pop();
			int topY = top.first.first;
			int topX = top.first.second;
			int value = top.second;
			if (((-1 < topY && topY < n) && (-1 < topX&&topX < n)) && !visited[topY][topX] && board[topY][topX] <= sharkSize)
			{
				if ((0 < board[topY][topX] && board[topY][topX] < sharkSize) && ((topY < nextY) || ((topY == nextY) && (topX <= nextX))))
				{
					nextY = topY;
					nextX = topX;
					//return pii(topY, topX);
				}
				visited[topY][topX] = 1;
				q.push(piii(pii(topY - 1, topX), value + 1));
				q.push(piii(pii(topY, topX - 1), value + 1));
				q.push(piii(pii(topY, topX + 1), value + 1));
				q.push(piii(pii(topY + 1, topX), value + 1));
			}
		}
		if (checkY != nextY || checkX != nextX)
		{
			sharkEat();
			resultTime += count;
			return pii(nextY, nextX);
		}
		count++;
	}
	return pii(-1, -1);
}
void solution() {
	while (shark != pii(-1, -1))
	{
		board[shark.first][shark.second] = 0;
		shark = bfs(shark);
		visitedClear();
	}
}
int main() {
	//init
	FastIO;
	cin >> n;
	int i, j, k;
	visitedTemp.resize(n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> input1;
			if (input1 == 9)
			{
				shark.first = i;
				shark.second = j;
				vtemp.push_back(0);
				continue;
			}
			vtemp.push_back(input1);
		}
		visited.push_back(visitedTemp);
		board.push_back(vtemp);
		vtemp.clear();
	}

	solution();
	cout << resultTime;
	return 0;
}
```
