[11054번: 가장 긴 바이토닉 부분 수열](https://www.acmicpc.net/problem/11054)

### 사고의 흐름

가장 긴 바이토닉 부분 수열은 가장 긴 증가하는 부분 수열과 가장 긴 감소하는 부분 수열을 합친 결과이다. 따라서 가장 긴 증가하는 부분 수열을 활용하면 풀 수 있는 문제였다.

감소하는 부분 수열을 구현하는데 조금 시간이 걸렸는데 구하는 방식이 잘못되었었다.
감소하는 부분 수열은 인덱스가 (n-1)에서 0까지 이동할 때 증가하는 부분 수열이라고 볼 수 있다.
따라서 for문에서 i가 감소하는 방식으로 진행해주면 된다.

---

가장 긴 증가하는 부분 수열을 푸는 방법은 다음과 같다.

1. dp[i]에 대하여 0~(i-1)의 인덱스 j를 탐색한다.
2. 입력 값을 저장한 배열 arr에 대하여 arr[j] < arr[i]를 만족하는 j 중에서 dp[j]가 가장 큰 것을 선택한다.
3.  dp[i] = dp[j] + 1 을 해주고 다음 인덱스 i로 넘어간다.

```cpp
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
```
