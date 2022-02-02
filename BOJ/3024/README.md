[3024번: 마라톤 틱택토](https://www.acmicpc.net/problem/3024)

### 사고의 흐름

오목, 틱택토 유형의 문제를 풀 때 늘 실수하고는 한다.

어떠한 돌이 한 줄로 있는 경우는 우향, 우하향, 하향 + 그리고 마지막으로 좌하향의 경우가 존재한다. 빼먹지 말고 늘 생각하고 진행하도록 하자.

```jsx
int n, m, t, N, K, itemp1, itemp2, itemp3;
string s[31];

void solution() {
	int i, j, k;
	for ( i = 0; i < n; i++)
	{
		for ( j = 0; j < n; j++)
		{
			if (s[i][j] == '.')
			{
				continue;
			}
			char ctemp = s[i][j];
			if (i <= n - 3 && j >= 2)
			{
				bool winner = true;
				for (k = 1; k < 3; k++)
				{
					if (s[i + k][j - k] != ctemp)
					{
						winner = false;
						break;
					}
				}
				if (winner)
				{
					cout << ctemp;
					return;
				}
			}
			if (i <= n - 3 && j <= n - 3)
			{
				bool winner = true;
				for ( k = 1; k < 3; k++)
				{
					if (s[i+k][j+k] != ctemp)
					{
						winner = false;
						break;
					}
				}
				if (winner)
				{
					cout << ctemp;
					return;
				}
			}
			if (i <= n - 3)
			{
				bool winner = true;
				for (k = 1; k < 3; k++)
				{
					if (s[i + k][j] != ctemp)
					{
						winner = false;
						break;
					}
				}
				if (winner)
				{
					cout << ctemp;
					return;
				}
			}
			if (j <= n - 3)
			{
				bool winner = true;
				for (k = 1; k < 3; k++)
				{
					if (s[i][j + k] != ctemp)
					{
						winner = false;
						break;
					}
				}
				if (winner)
				{
					cout << ctemp;
					return;
				}
			}
		}
	}
	cout << "ongoing";
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
	for ( i = 0; i < n; i++)
	{
		cin >> s[i];
	}
}
```
