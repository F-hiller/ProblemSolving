[5576번: 콘테스트](https://www.acmicpc.net/problem/5576)

```cpp
	for ( i = 0; i < 10; i++)
	{
		cin >> v1[i];
	}
	for (i = 0; i < 10; i++)
	{
		cin >> v2[i];
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	for ( i = 0; i < 3; i++)
	{
		result1 += v1[9 - i];
		result2 += v2[9 - i];
	}
	cout << result1 << " " << result2;
```
