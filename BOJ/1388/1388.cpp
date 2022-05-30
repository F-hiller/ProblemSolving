int t, n, m, input1, input2;
string arr[51];
bool visited[51][51];

void solution() {
	int result = 0;
	int i, j, k;
	for ( i = 0; i < n; i++)
	{
		for ( j = 0; j < m; j++)
		{
			if (!visited[i][j])
			{
				int y = i;
				int x = j;

				visited[i][j] = 1;

				result++;

				if (arr[i][j] == '-')
				{
					x++;
					while (x < m && arr[i][x] == '-' && !visited[i][x])
					{
						visited[i][x] = 1;
						x++;
					}
				}
				else
				{
					y++;
					while (y < n && arr[y][j] == '|' && !visited[y][j])
					{
						visited[y][j] = 1;
						y++;
					}
				}
			}
		}
	}
	cout << result;
}

int main() {
	//init
	FastIO;
	int i, j, k;
	cin >> n >> m;
	for ( i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	solution();

	return 0;
}
