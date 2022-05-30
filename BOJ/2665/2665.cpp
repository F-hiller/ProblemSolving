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
