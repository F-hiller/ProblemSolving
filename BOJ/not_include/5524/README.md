[5524번: 입실 관리](https://www.acmicpc.net/problem/5524)

```cpp
	string s;
	cin >> n;
	for ( i = 0; i < n; i++)
	{
		cin >> s;
		for ( j = 0; j < s.size(); j++)
		{
			cout << (char)tolower(s[j]);
		}
		cout << endl;
	}
```
