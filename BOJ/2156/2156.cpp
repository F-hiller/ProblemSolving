	dp[1] = grape[1];
	dp[2] = dp[1] + grape[2];
	for ( i = 3; i <= n; i++)
	{
		dp[i] = max(dp[i - 1], max(dp[i - 2] + grape[i], dp[i - 3] + grape[i - 1] + grape[i]));
	}
	cout << dp[n];
