[1238번: 파티](https://www.acmicpc.net/problem/1238)

### 사고의 흐름

bfs로만 계속 시도를 해서 다익스트라로 해결할 수 있는지에 대해 생각하지 못하였다. 관련 내용을 검색하다가 시간을 줄일 수 있는 방법에 대한 내용을 발견했다.

아래에 있는 코드에서의 입력은 a b c가 있다면 a에서 b로가는 길의 값이 c라는 의미로 map[a][b] = c로 진행하였다. 그렇기에 모든 마을의 학생들이 x 마을에 방문하기 위해서 진행하는 경우 시작점 i를 기준으로 n번의 다익스트라를 진행해야한다. 

하지만 입력의 관계를 역순으로 한다면 다르게 해석할 수 있다. 입력 a b c가 있다면 b에서 도착하고 a에서 출발하는 길의 값이 c라는 의미로 map[b][a] = c라고 정할 수 있다. 이 경우 파티가 열리는 x마을을 시작점으로 다익스트라를 한번만 한다면 x에서 모든 정점의 경로를 역순으로 탐색할 수 있게 된다. 즉 모든 정점에서 x까지 가는 경로의 최단 시간을 한번의 다익스트라로 구할 수 있다는 의미가 되며 정점 수가 많아질 때도 사용할 수 있게 된다.

```cpp
int n, m, t, N, K, itemp1, itemp2, itemp3;
int map[1001][1001];
int x;
int dist[1001], go[1001], back[1001];
bool visited[1001];

void clear() {
	int i, j, k;
	for (i = 1; i <= n; i++)
	{
		visited[i] = 0;
	}
}
void djk(int start) {
	int i, j, k;
	int cur_node = start;
	for ( i = 1; i <= n; i++)
	{
		if (i == cur_node)
		{
			dist[i] = 0;
			continue;
		}
		dist[i] = map[cur_node][i];
	}
	visited[cur_node] = 1;

	int value_min, index;
	while (true)
	{
		value_min = INF;
		for ( i = 1; i <= n; i++)
		{
			if (!visited[i] && value_min > dist[i])
			{
				value_min = dist[i];
				index = i;
			}
		}
		if (value_min == INF)
		{
			break;
		}
		cur_node = index;
		for (i = 1; i <= n; i++)
		{
			if (dist[i] > value_min + map[cur_node][i])
			{
				dist[i] = value_min + map[cur_node][i];
			}
		}
		visited[cur_node] = 1;
		if (start != x && cur_node == x)
		{
			break;
		}
	}
	if (start == x)
	{
		for ( i = 1; i <= n; i++)
		{
			back[i] = dist[i];
		}
	}
	else
	{
		go[start] = dist[x];
	}
}

void solution() {
	int i, j, k;
	for ( i = 1; i <= n; i++)
	{
		djk(i);
		clear();
	}
	int value_max = 0;
	for (i = 1; i <= n; i++)
	{
		if (go[i]+back[i] > value_max)
		{
			value_max = go[i] + back[i];
		}
	}
	cout << value_max;
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
	cin >> n >> m >> x;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			map[i][j] = INF;
		}
	}
	for ( i = 0; i < m; i++)
	{
		cin >> itemp1 >> itemp2 >> itemp3;
		map[itemp1][itemp2] = itemp3;
	}
}
```
