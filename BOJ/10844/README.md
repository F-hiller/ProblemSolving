[10844번: 쉬운 계단 수](https://www.acmicpc.net/problem/10844)

### 사고의 흐름

dp문제이며 풀이 과정은 다음과 같다.

---

3이상인 i번째 수는 i-1번째 수에서 낮아지거나 높아진다. 
만약 i번째 수가 j라면 i-1번째 수는 j+1이거나 j-1이어야만 한다.

따라서 dp[i][j] = dp[i - 1][j + 1] + dp[i - 1][j - 1]가 된다.

하지만 0과 9의 경우 -1과 10이 존재할 수 없으므로 그 부분을 따로 구현해줘야한다. 

마지막으로 0으로 시작할 수 없기에 dp[1][0] = 0으로 표현해준다.

```cpp
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
```
