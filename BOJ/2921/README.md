[2921번: 도미노](https://www.acmicpc.net/problem/2921)

```cpp
int t, n, m, input1, input2;
int main() {
	//init
	FastIO;
	int i, j, k;
	cin >> n;

	int result = 0;
	for (i = 0; i <= n; i++)
	{
		for (j = i; j <= n; j++)
		{
			result += (i + j);
		}
	}
	cout << result;

	return 0;
}
```
