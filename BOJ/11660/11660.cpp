int n, m, itemp1, itemp2, itemp3;
int arr[MAX_SIZE][MAX_SIZE], dp[MAX_SIZE][MAX_SIZE];

int main() {
	//init
	FastIO;
	int i, j, k;
	pii p1, p2;
	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	dp[0][0] = arr[0][0];
	for (i = 1; i < n; i++)
	{
		dp[0][i] = dp[0][i - 1] + arr[0][i];
		dp[i][0] = dp[i - 1][0] + arr[i][0];
	}
	for (i = 1; i < n; i++)
	{
		for (j = 1; j < n; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
		}
	}
	if (DEBUG)
	{
		cout << "========================" << endl;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		cout << "========================" << endl;
	}
	for (i = 0; i < m; i++)
	{
		cin >> p1.first >> p1.second >> p2.first >> p2.second;
		p1.first--;
		p1.second--;
		p2.first--;
		p2.second--;
		int base = dp[p2.first][p2.second], sub1 = 0, sub2 = 0, add1 = 0;
		if (p1.first > 0 && p1.second > 0)
		{
			add1 = dp[p1.first - 1][p1.second - 1];
		}
		if (p1.second > 0)
		{
			sub1 = dp[p2.first][p1.second - 1];
		}
		if (p1.first > 0)
		{
			sub2 = dp[p1.first - 1][p2.second];
		}
		cout << base - sub1 - sub2 + add1 << endl;
	}

	return 0;
}
