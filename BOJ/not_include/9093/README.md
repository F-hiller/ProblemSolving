[9093번: 단어 뒤집기](https://www.acmicpc.net/problem/9093)

- 지난 번 문제처럼 한 줄 전체를 입력으로 받는 문제에서는 (ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);)부분을 주석처리 해줘야했다.

```cpp
	string s;
	stack<char> stk;
	cin >> n;
	getchar();
	for ( i = 0; i < n; i++)
	{
		getline(cin, s);
		for ( j = 0; j < s.size(); j++)
		{
			if (s[j] != ' ')
			{
				stk.push(s[j]);
			}
			else
			{
				while (!stk.empty())
				{
					cout << stk.top();
					stk.pop();
				}
				cout << " ";
			}
		}
		while (!stk.empty())
		{
			cout << stk.top();
			stk.pop();
		}
		cout << endl;
	}
```
