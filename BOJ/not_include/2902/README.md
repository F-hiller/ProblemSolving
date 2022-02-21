[2902번: KMP는 왜 KMP일까?](https://www.acmicpc.net/problem/2902)

```cpp
	string s;
	cin >> s;
	cout << s[0];
	for ( i = 1; i < s.size() - 1; i++)
	{
		if (s[i] == '-')
		{
			cout << s[i + 1];
		}
	}
```
