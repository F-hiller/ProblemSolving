int n, m, t, N, K, itemp1, itemp2, itemp3;
vector<int> v;
int dp[1001], dp_down[1001];

void solution() {
	int i, j, k;
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
	//dp_down
	for (i = n - 1; i > -1; i--)
	{
		int index = i;
		int value = dp_down[i]; 
		for (j = n - 1; j > i; j--)
		{
			if (dp_down[j] + 1 >= value && v[j] < v[i])
			{
				index = j;
				value = dp_down[j] + 1;
			}
		}
		dp_down[i] = value;
	}

	int result = 0;
	for (i = 0; i < n; i++)
	{
		if (dp[i] + dp_down[i] > result)
		{
			result = dp[i] + dp_down[i];
		}
	}
	cout << result - 1;
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
		cin >> itemp1;
		v.push_back(itemp1);
		dp[i] = 1;
		dp_down[i] = 1;
	}
}
