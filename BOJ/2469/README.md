[2469번: 사다리 타기](https://www.acmicpc.net/problem/2469)

## 사고의 흐름

사다리의 비어있는 한줄을 맞추는 문제이다. 사다리가 연속으로 놓여있는 경우는 배제한다고 문제에 있으므로 잘 활용해야한다. 시작(ABCDE~)에서 ?라인까지 내려가는 과정을 거친 문자열 S1과 입력을 통해 얻은 사다리의 결과에서 ?라인까지 올라가는 과정을 거친 문자열 S2를 구해서 서로 비교해주면 된다. 내려가거나 올라가는 과정은 가로줄 ’-’이 있는 라인의 두 문자들을 바꿔주는 과정으로 동일하다.

```cpp
int n, m, t, itemp1, itemp2;
string down_top, result;
string ladder[1000];
char top_down[26];
char ctemp;

void solution() {
	int i, j, k;
	//top to down
	for ( i = 0; i < m; i++)
	{
		if (ladder[i][0]=='?')
		{
			break;
		}
		for ( j = 0; j < n - 1; j++)
		{
			if (ladder[i][j] == '*')
			{
				continue;
			}
			ctemp = top_down[j];
			top_down[j] = top_down[j + 1];
			top_down[j + 1] = ctemp;
		}
	}
	//down to top
	for ( i = m - 1; i > -1; i--)
	{
		if (ladder[i][0] == '?')
		{
			break;
		}
		for (j = 0; j < n - 1; j++)
		{
			if (ladder[i][j] == '*')
			{
				continue;
			}
			ctemp = down_top[j];
			down_top[j] = down_top[j + 1];
			down_top[j + 1] = ctemp;
		}
	}
	//compare top_down and down_top
	//cout << top_down << endl << down_top << endl;
	for ( i = 0; i < n - 1; i++)
	{
		if (top_down[i] == down_top[i])
		{
			result.push_back('*');
			continue;
		}
		if (top_down[i] == down_top[i+1]&&top_down[i+1] == down_top[i])
		{
			ctemp = down_top[i];
			down_top[i] = down_top[i + 1];
			down_top[i + 1] = ctemp;
			result.push_back('-');
			continue;
		}
		for ( i = 0; i < n - 1; i++)
		{
			cout << 'x';
		}
		return;
	}
	cout << result;
}

int main() {
	//init
	FastIO;
	//init
	int i, j, k;
	init();

	solution();

	return 0;
}

void init() {
	int i, j, k;
	cin >> n >> m;
	cin >> down_top;
	for ( i = 0; i < m; i++)
	{
		cin >> ladder[i];
	}
	for ( i = 0; i < n; i++)
	{
		top_down[i] = i + 'A';
	}
}
```
