	cin >> n;
	long long dp[101][101] = { 0, };
	for (i = 1; i < 10; i++)
	{
		dp[1][i] = 1;
	}
	for (i = 1; i < 9; i++)
	{
		dp[2][i] += dp[1][i + 1];
		dp[2][i] += dp[1][i - 1];
	}
	dp[2][0] = dp[1][1];
	dp[2][9] = dp[1][8];
	for (i = 3; i <= n; i++)
	{
		for (j = 1; j < 9; j++)
		{
			dp[i][j] += dp[i - 1][j + 1];
			dp[i][j] %= SHARING;
			dp[i][j] += dp[i - 1][j - 1];
			dp[i][j] %= SHARING;
		}
		dp[i][0] += dp[i - 1][1];
		dp[i][9] += dp[i - 1][8];
		dp[i][0] %= SHARING;
		dp[i][9] %= SHARING;
	}
	long long result = 0;
	for (i = 0; i < 10; i++)
	{
		result += dp[n][i];
		result %= SHARING;
	}
	cout << result;
