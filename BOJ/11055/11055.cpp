int n, m, t, N, K, itemp1, itemp2, itemp3;
int arr[1030];
int dp[1030];

void solution() {
	int i, j, k;
	dp[0] = arr[0];
	for ( i = 1; i < n; i++)
	{
		int dp_max = 0;
		int dp_index = 0;
		for ( j = 0; j < i; j++)
		{
			if (arr[j] < arr[i] && dp_max < dp[j]+arr[i])
			{
				dp_index = j;
				dp_max = dp[j] + arr[i];
			}
		}
		if (dp_max == 0)
		{
			dp[i] = arr[i];
			continue;
		}
		dp[i] = dp_max;
	}
	int result = 0;
	for ( i = 0; i < n; i++)
	{
		if (result < dp[i])
		{
			result = dp[i];
		}
	}
	cout << result;
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
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}
