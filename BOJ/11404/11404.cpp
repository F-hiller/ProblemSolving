//additional variables
int dist[101][101];

//main function
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//init
	int i, j, k;
	int start, finish, cost;
	//solution
	cin >> n >> m;
	for ( i = 1; i <= n; i++)
	{
		for ( j = 1; j <= n; j++)
		{
			if (i == j)
			{
				dist[i][j] = 0;
			}
			else
			{
				dist[i][j] = INF;
			}
		}
	}
	for ( i = 0; i < m; i++)
	{
		cin >> start >> finish >> cost;
		dist[start][finish] = min(cost, dist[start][finish]);
	}
	for ( i = 1; i <= n; i++)
	{
		// i 는 거쳐가는 노드 N
		for ( j = 1; j <= n; j++)
		{
			if (i == j)
			{
				continue;
			}
			for ( k = 1; k <= n; k++)
			{
				if (i == k || j == k)
				{
					continue;
				}
				//진행하는 곳
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
			}
		}
	}
	for ( i = 1; i <= n; i++)
	{
		for ( j = 1; j <= n; j++)
		{
			if (dist[i][j] == INF)
			{
				cout << "0 ";
				continue;
			}
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
