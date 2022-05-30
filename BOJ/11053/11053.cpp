int t, i, j, k, n, m, a, b, c, d, e, itemp1, itemp2;
vector<int> v;
int dp[1001];

int main() {
	//init
	FastIO;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> itemp1;
		v.push_back(itemp1);
		dp[i] = 1;
	}
	for (i = 0; i < n; i++)
	{
		int index = i;
		int value = dp[i]; //부분수열의 길이
		for (j = 0; j < i; j++)
		{
			if (dp[j] + 1 >= value && v[j] < v[i])
			{
				index = j;
				value = dp[j] + 1;
			}
		}
		dp[i] = value;
	}
	int result = 0;
	for (i = 0; i < n; i++)
	{
		if (dp[i] > result)
		{
			result = dp[i];
		}
	}
	cout << result;
	return 0;
}
