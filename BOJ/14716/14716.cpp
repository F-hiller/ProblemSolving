int i, j, k, n, m, itemp1, itemp2, itemp3;
bool arr[500][500];
bool visited[500][500];
int result_cnt = 0;

void bfs(int y, int x) {
	result_cnt++;
	queue<pii> q;
	q.push(pii(y, x));
	int temp_area = 0;
	while (!q.empty())
	{
		pii top = q.front();
		q.pop();
		int topY = top.first;
		int topX = top.second;
		if ((-1 < topY && topY < n && -1 < topX && topX < m) && !visited[topY][topX] && arr[topY][topX] == 1)
		{
			visited[topY][topX] = 1;
			temp_area++;
			q.push(pii(topY + 1, topX));
			q.push(pii(topY - 1, topX));
			q.push(pii(topY, topX + 1));
			q.push(pii(topY, topX - 1));

			q.push(pii(topY+1, topX - 1));
			q.push(pii(topY+1, topX + 1));
			q.push(pii(topY-1, topX - 1));
			q.push(pii(topY-1, topX + 1));
		}
	}
}

int main() {
	//init
	FastIO;

	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (!visited[i][j] && arr[i][j] == 1)
			{
				bfs(i, j);
			}
		}
	}

	cout << result_cnt;
	return 0;
}
