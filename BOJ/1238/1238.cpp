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
