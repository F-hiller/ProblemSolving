[1935번: 후위 표기식2](https://www.acmicpc.net/problem/1935)

### 사고의 흐름

A~Z에 해당하는 값을 abc[]배열에 저장한다.

입력을 통해 받은 문자열에서 영문자(A~Z)를 발견하면 abc[s[i] - ‘A’]식을 통해 해당 문자를 바탕으로 배열에서 값을 가져올 수 있다.

그 외에는 후기표기식을 계산하는 방식으로 진행하였다.

```cpp
//additional variables
string s;
stack<double> stk;
double fir, sec, input;
int abc[27];

//main function
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//init
	int i, j, k, itemp;
	//solution
	cin >> n>>s;
	for ( i = 0; i < n; i++)
	{
		cin >> abc[i];
	}
	for ( i = 0; i < s.size(); i++)
	{
		if ('A' <= s[i] && s[i] <= 'Z')
		{
			stk.push(abc[s[i] - 'A']);
			continue;
		}
		sec = stk.top();
		stk.pop();
		fir = stk.top();
		stk.pop();
		if (s[i] == '*')
		{
			input = fir * sec;
		}
		else if (s[i] == '/')
		{
			input = fir / sec;
		}
		else if (s[i] == '+')
		{
			input = fir + sec;
		}
		else if (s[i] == '-')
		{
			input = fir - sec;
		}
		stk.push(input);
	}
	printf("%.2lf", stk.top());

	return 0;
}
```
