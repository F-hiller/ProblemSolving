[10819번: 차이를 최대로](https://www.acmicpc.net/problem/10819)

## 사고의 흐름

경우의 수가 최대 8! = 40320개로 모든 경우를 살펴보면서 해결이 가능하다.

```cpp
int t, n, m, input1, input2;
vector<int> v;
bool visited[10];
int ans[10];
int result = 0;

void solution(int depth) {
	int i, j, k;
	if (depth == n)
	{
		int sum = 0;
		for ( i = 1; i < n; i++)
		{
			sum += abs(ans[i - 1] - ans[i]);
		}
		if (sum > result)
		{
			result = sum;
		}
		return;
	}
	for ( i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			ans[depth] = v[i];
			solution(depth + 1);
			visited[i] = 0;
		}
	}
}

int main() {
	//init
	FastIO;
	int i, j, k;
	cin >> n;
	for ( i = 0; i < n; i++)
	{
		cin >> input1;
		v.push_back(input1);
		visited[i] = 0;
	}

	solution(0);

	cout << result;

	return 0;
}
```
