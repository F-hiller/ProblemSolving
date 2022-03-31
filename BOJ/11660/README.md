[11660번: 구간 합 구하기 5](https://www.acmicpc.net/problem/11660)

### 사고의 흐름

2차원 dp를 이용하는 문제이다.

dp에 저장해야하는 값은 좌표(i, j)에 대하여 (0, 0) - (i, 0) - (0, j) - (i, j) 네 좌표를 끝으로 하는 직사각형 범위에 누적 값이다.

이를 이용하면 { (x1, y1)부터 (x2, y2)의 합 } = dp[x2][y2] - dp[x1][y2] - dp[x2][y1] + dp[x1][y1] 으로 나타낼 수 있다.

마지막으로 고려해줄 사항은 x나 y가 0인 경우  dp[x1][y2], dp[x2][y1], dp[x1][y1]값들이 0이 될 수 있으므로 해당 사항을 반영해주어야한다.

```cpp
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
```
