[2587번: 대표값2](https://www.acmicpc.net/problem/2587)

```cpp
	for ( i = 0; i < 5; i++)
	{
		cin >> arr[i];
		result += arr[i];
	}
	sort(arr.begin(), arr.end());
	cout << result/5 << " " << arr[2];
```
