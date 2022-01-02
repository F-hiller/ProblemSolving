[1406번: 에디터](https://www.acmicpc.net/problem/1406)

## 사고의 흐름

스택을 사용하는 문제이다. 글자를 중간에 넣을 수 있다는 것에서 스택을 생각할 수 있어야한다. 벡터, 배열, 리스트, 집합에서는 중간에 무언가를 넣을 수 없으므로 다른 자료형을 생각했어야했다.

```cpp
int i, j, k, n, m, t, itemp1, itemp2;
string str;
char cmd, ctemp;
stack<char> s, result;

int main() {
	//init
	FastIO;
	//init
	init();

	cin >> str;
	for ( i = 0; i < str.size(); i++)
	{
		s.push(str[i]);
	}
	cin >> n;
	for ( i = 0; i < n; i++)
	{
		cin >> cmd;
		if (cmd == 'P')
		{
			cin >> ctemp;
			s.push(ctemp);
		}
		else if (cmd == 'L' && !s.empty())
		{
			result.push(s.top());
			s.pop();
		}
		else if (cmd == 'D' && !result.empty())
		{
			s.push(result.top());
			result.pop();
		}
		else if (cmd == 'B' && !s.empty())
		{
			s.pop();
		}
	}
	while (!s.empty())
	{
		result.push(s.top());
		s.pop();
	}
	while (!result.empty())
	{
		cout << result.top();
		result.pop();
	}
	return 0;
}
```
