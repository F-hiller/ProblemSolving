[https://www.acmicpc.net/problem/10807](https://www.acmicpc.net/problem/10807)

```cpp
int i, j, k;
	int result = 0;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cin >> m;
	for (i = 0; i < n; i++)
	{
		if (arr[i] == m)
		{
			result++;
		}
	}
	cout << result;
```
