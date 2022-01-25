[11055번: 가장 큰 증가 부분 수열](https://www.acmicpc.net/problem/11055)

## 사고의 흐름

가장 긴 바이토닉 부분 수열 문제를 풀다가 해결하지 못하여 이 문제를 풀게되었다. 감소하는 부분 수열을 구현하면 그 문제를 다시 풀 수 있을 것 같다. 

증가하는 부분 수열 문제의 변형 문제이다. 증가하는 부분 수열 중에서 값의 합이 가장 큰 수열을 찾는 문제이다. 증가하는 부분 수열 문제는 dp에 지금까지 부분 수열의 길이를 기록하였지만 여기서는 부분 수열의 값의 합을 기록해주었다.

```jsx
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
```
