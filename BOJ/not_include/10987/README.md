[10987번: 모음의 개수](https://www.acmicpc.net/problem/10987)

```cpp
	string s;
	cin >> s;
	int cnt = 0;
	for ( i = 0; i < s.size(); i++)
	{
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
		{
			cnt++;
		}
	}
	cout << cnt;
```
