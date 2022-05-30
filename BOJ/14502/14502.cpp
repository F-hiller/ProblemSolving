int t, n, m, a, b, c, d, e, itemp1, itemp2;
int map[8][8];
int mapSave[8][8];
int result = -987654321;

void bfs() {
	bool bfsVisited[8][8];
	queue<pii> q;
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (map[i][j] == 2)
			{
				q.push(pii(i, j));
			}
			bfsVisited[i][j] = 0;
		}
	}
	while (!q.empty())
	{
		pii top = q.front();
		q.pop();
		int topY = top.first;
		int topX = top.second;
		if (-1 < topY && topY < n && -1 < topX && topX < m && map[topY][topX] != 1 && !bfsVisited[topY][topX])
		{
			bfsVisited[topY][topX] = 1;
			map[topY][topX] = 2;
			q.push(pii(topY + 1, topX));
			q.push(pii(topY - 1, topX));
			q.push(pii(topY, topX + 1));
			q.push(pii(topY, topX - 1));
		}
	}
}

void mapRefresh() {
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			map[i][j] = mapSave[i][j];
		}
	}
}

pii selectWall[3];
bool visited[8][8];
void solution(int depth) {
	int i, j, k;
	if (depth == 3)
	{
		for (i = 0; i < 3; i++)
		{
			map[selectWall[i].first][selectWall[i].second] = 1;
		}

		bfs();

		int count = 0;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if (map[i][j] == 0)
				{
					count++;
				}
			}
		}
		if (count > result)
		{
			result = count;
		}
		mapRefresh();
		return;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			bool check = 0;
			for (k = 0; k < depth; k++)
			{
				if (i < selectWall[k].first || (i == selectWall[k].first && j <= selectWall[k].second))
				{
					check = 1;
					break;
				}
			}
			if (!visited[i][j] && !check && map[i][j] == 0)
			{
				visited[i][j] = 1;
				selectWall[depth] = pii(i, j);
				solution(depth + 1);
				visited[i][j] = 0;
			}
		}
	}

}

int main() {
	//init
	FastIO;
	int i, j, k;
	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> mapSave[i][j];
		}
	}
	mapRefresh();

	solution(0);

	cout << result;

	return 0;
}
