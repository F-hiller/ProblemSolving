[1357번: 뒤집힌 덧셈](https://www.acmicpc.net/problem/1357)

```cpp
string a, b, rev_a, rev_b, rev_result, result;
	cin >> a >> b;
	while (a.size())
	{
		rev_a.push_back(a.back());
		a.pop_back();
	}
	while (b.size())
	{
		rev_b.push_back(b.back());
		b.pop_back();
	}
	rev_result = to_string(stoi(rev_a) + stoi(rev_b));
	while (rev_result.size())
	{
		result.push_back(rev_result.back());
		rev_result.pop_back();
	}
	cout << stoi(result);
```
