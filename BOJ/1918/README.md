[1918번: 후위 표기식](https://www.acmicpc.net/problem/1918)

## 사고의 흐름

2~3일 정도 생각해봐도 답이 안나와서 결국 인터넷을 통해 코드를 마저 구현하였다. 스택을 활용하는 기본적인 문제이므로 다음에 꼭 다시 풀어봐야겠다.

중요한 점은 +-와 */의 차이에서부터 시작한다.

```cpp
int t, n, m, a, b, c, d, e, itemp1, itemp2;
string str;
stack<char> s;
int main() {
	//init
	FastIO;
	cin >> str;
	int i, j, k;
	for (i = 0; i < str.size(); i++)
	{
		char ctemp = str[i];
		if (('A' <= ctemp && ctemp <= 'Z'))
		{
			cout << ctemp;
			continue;
		}
		if (ctemp == '(')
		{
			s.push(ctemp);
			continue;
		}
		if (ctemp == ')')
		{
			while (s.top() != '(')
			{
				cout << s.top();
				s.pop();
			}
			s.pop();
			continue;
		}
		if ((ctemp == '+' || ctemp == '-'))
		{
			while (!s.empty())
			{
				if (s.top() == '(') {
					break;
				}
				cout << s.top();
				s.pop();
			}
			s.push(ctemp);
			continue;
		}
		if ((ctemp == '*' || ctemp == '/'))
		{
			while (!s.empty() && (s.top() != '+' && s.top() != '-' && s.top() != '('))
			{
				cout << s.top();
				s.pop();
			}
			s.push(ctemp);
			continue;
		}
	}
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
	return 0;
}
```
