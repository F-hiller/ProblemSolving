[11053번: 가장 긴 증가하는 부분 수열](https://www.acmicpc.net/problem/11053)
## 사고의 흐름

이런 문제들은 대부분 백트래킹을 먼저 시도해보는 경향이 있는 것 같다. DP를 바로 생각할 수 있도록 하자.

i번째 수열에서는 앞의 수열들 중에서 가장 긴 부분 수열을 +1해서 이어받아주면 된다. 당연한 이야기지만 증가하는 부분수열의 조건을 만족해야한다.(앞의 수열이 1, 3, 5, 7인데 다음에 올 숫자를 4로 고르면 안된다는 뜻이다.)

```cpp
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
```
