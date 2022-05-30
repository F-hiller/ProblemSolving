int i, j, k, n, m, itemp1, itemp2;
int itemp3;
vector<int> v[3];
vector<int> dp[3];

int main() {
	//init
	FastIO;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> itemp1 >> itemp2 >> itemp3;
		v[0].push_back(itemp1);
		v[1].push_back(itemp2);
		v[2].push_back(itemp3);
	}
	for ( i = 0; i < 3; i++)
	{
		dp[i].push_back(v[i][0]);
	}
	for ( i = 0; i < n - 1; i++)
	{
		dp[1].push_back(dp[0][i] + v[1][i + 1]);
		dp[2].push_back(dp[0][i] + v[2][i + 1]);
		dp[0].push_back(dp[1][i] + v[0][i + 1]);
		dp[2][i + 1] = min(dp[2][i + 1], dp[1][i] + v[2][i + 1]);
		dp[0][i + 1] = min(dp[0][i + 1], dp[2][i] + v[0][i + 1]);
		dp[1][i + 1] = min(dp[1][i + 1], dp[2][i] + v[1][i + 1]);
	}
	//result
	cout << min(min(dp[0][n - 1], dp[1][n - 1]), dp[2][n - 1]);
	return 0;
}
