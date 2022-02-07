[24392번: 영재의 징검다리](https://www.acmicpc.net/problem/24392)

### 사고의 흐름

dp 문제로 쉬운 계단 문제와 유사하다. 

갈 수 있는 경우가 아니라 해당 칸으로 올 수 있는 경우의 수를 배열에 더해주면서 모든 경우를 세었다.

```cpp
//additional variables
int bridge[1001][1001];
long long dp[1001][1001];

//main function
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//init
	int i, j, k;
	long long result = 0, div = 1000000007;
	//solution
	cin >> n >> m;
	for ( i = 0; i < n; i++)
	{
		for ( j = 0; j < m; j++)
		{
			cin >> bridge[i][j];
			dp[i][j] = 0;
		}
	}
	for ( i = 0; i < m; i++)
	{
		dp[0][i] = bridge[0][i];
	}
	for ( i = 1; i < n; i++)
	{
		for ( j = 0; j < m; j++)
		{
			if (bridge[i][j])
			{
				dp[i][j] += dp[i - 1][j];
				if (j != 0)
				{
					dp[i][j] += dp[i-1][j-1];
				}
				dp[i][j] %= div;
				if (j != m - 1)
				{
					dp[i][j] += dp[i - 1][j + 1];
				}
				dp[i][j] %= div;
			}
		}
	}
	for ( i = 0; i < m; i++)
	{
		result += dp[n - 1][i];
		result %= div;
	}
	cout << result;
	return 0;
}
```
