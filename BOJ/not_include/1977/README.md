[https://www.acmicpc.net/problem/1977](https://www.acmicpc.net/problem/1977)

```cpp
int t, n, m, input1, input2;
int main() {
	//init
	FastIO;
	int i, j, k;
	cin >> m >> n;
	int result = 0;
	int minValue = 987654321;
	for ( i = 1; i < 101; i++)
	{
		int itemp = i * i;
		if (m <= itemp && itemp <= n)
		{
			if (minValue > itemp)
			{
				minValue = itemp;
			}
			result += itemp;
		}
	}
	if (result)
	{
		cout << result << endl << minValue;
		return 0;
	}
	cout << -1;
	return 0;
}
```
