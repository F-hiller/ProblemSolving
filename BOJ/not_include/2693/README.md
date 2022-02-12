[2693번: N번째 큰 수](https://www.acmicpc.net/problem/2693)

```cpp
	cin >> t;
	for ( i = 0; i < t; i++)
	{
		for ( j = 0; j < 10; j++)
		{
			cin >> arr[j];
		}
		sort(arr.begin(), arr.end());
		cout << arr[7] << endl;
	}
```
