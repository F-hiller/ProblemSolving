[2206번: 벽 부수고 이동하기](https://www.acmicpc.net/problem/2206)

## 사고의 흐름

bfs문제이다. 막힌 벽을 한칸까지만 뚫어서 도착지까지 최단거리를 구하는 문제로 모든 부술 수 있는 벽을 부숴보면서 진행하면 당연히 시간초과가 걸린다. 어떻게 풀지 도저히 감을 못잡아서 풀이법에 대해서 알아보았다. 그러자 visited배열에 차원을 하나 더 추가하면 해결된다는 말이 대부분이어서 이해하는데 시간이 조금 걸렸다.

앞서 말했듯이 모든 벽을 부숴보고 bfs를 진행하면 시간초과가 걸린다. 그래서 bfs탐색을 진행하면서 벽을 부쉈는지 여부를 하나의 차원으로 새로 만들어 표현하는 것이다. visited[50][60][0]이 의미하는 바는 현재 방문한 곳의 위치가 좌표(50, 60)이고 아직까지 벽을 부수지 않았음(0)이다. 

차원을 추가하는 이유를 아래의 경우를 통해 설명할 수 있다. - (백준 질문 답변자의 예시)

```cpp
000000
111110
010000
010111
010011
011011
000*10
```

시작점에서 (1, 0)의 벽을 뚫고 *위치까지 도달한 경우는 목적지에 도착할 수 없다. 하지만 벽을 뚫지 않고 *까지 도달했을 때 *위치의 visited값은 이미 1이므로 벽을 뚫고 목적지에 도달할 수 없게 된다. 이를 해결하기 위해 차원을 하나 추가했고 (1, 0)의 벽을 뚫고 *위치에 도달한 경우는 visited[y][x][1]의 값이 1이 된다. 벽을 뚫지 않고 *위치에 도달하면 visited[y][x][0]의 값을 확인하게되고 옆의 벽을 뚫고 목적지에 도착할 수 있게 된다.

배열을 이용한 문제가 해결이 안될 때는 차원을 추가해보는 방법도 있다는 것을 알게되었다.

```cpp
int n, m, t, itemp1, itemp2;
string map[1000];
bool visited[1000][1000][2];

void solution() {
	int i, j, k;
	queue<piii> q;
	q.push(piii(pii(0, 0), pii(0, 1)));
	while (!q.empty())
	{
		piii top = q.front();
		q.pop();
		int topY = top.first.first;
		int topX = top.first.second;
		int isBreak = top.second.first;
		int value = top.second.second;
		if (topY == n-3 && topX == m-1)
		{
			cout << "";
		}
		if (topY == n - 1 && topX == m - 1)
		{
			cout << value;
			return;
		}
		if (-1 < topY&&topY < n &&-1 < topX&&topX < m && !visited[topY][topX][isBreak])
		{
			visited[topY][topX][isBreak] = 1;
			if (map[topY][topX] == '1' )
			{
				if (isBreak)
				{
					continue;
				}
				q.push((piii(pii(topY + 1, topX), pii(1, value + 1))));
				q.push((piii(pii(topY, topX - 1), pii(1, value + 1))));
				q.push((piii(pii(topY, topX + 1), pii(1, value + 1))));
				q.push((piii(pii(topY - 1, topX), pii(1, value + 1))));
				continue;
			}
			q.push((piii(pii(topY + 1, topX), pii(isBreak, value + 1))));
			q.push((piii(pii(topY, topX - 1), pii(isBreak, value + 1))));
			q.push((piii(pii(topY, topX + 1), pii(isBreak, value + 1))));
			q.push((piii(pii(topY - 1, topX), pii(isBreak, value + 1))));
		}
	}
	cout << -1;
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
	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		cin >> map[i];
	}
}
```
