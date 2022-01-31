[Problem - B - Codeforces](https://codeforces.com/contest/1633/problem/B)

### 사고의 흐름

dp를 안써도 되는 문제인데 괜히 쓴 것 같다.

0과 1로 이루어진 문자열의 substring에서 갯수가 적은 문자가 최대 몇개인가를 묻는 문제이다.

모든 경우는 두 개의 과정으로 해결할 수 있다.

문자열 입력 s에 대하여

1. s에서 0과 1의 갯수가 같다.

어느 하나의 갯수 - 1이 정답이 된다. ex) 0이 5개 1이 5개면 5 - 1 = 4가 정답이다.

1. 0과 1의 갯수가 다르다.

갯수가 작은 것이 정답이 된다. ex) 0이 5개 1이 4개면 min(5, 4) = 4가 정답이다.

```bash
int n, m, t, N, K, itemp1, itemp2, itemp3;
string s;
int dp0[200001], dp1[200001];
void solution() {
	int i, j, k;
	if (s[0] == '0')
	{
		dp0[0] = 1;
		dp1[0] = 0;
	}
	else
	{
		dp0[0] = 0;
		dp1[0] = 1;
	}
	for (i = 1; i < s.size(); i++)
	{
		if (s[i] == '0')
		{
			dp0[i] = dp0[i - 1] + 1;
			dp1[i] = dp1[i - 1];
		}
		else
		{
			dp0[i] = dp0[i - 1];
			dp1[i] = dp1[i - 1] + 1;
		}
	}
	i = s.size() - 1;
	if (dp0[i] != dp1[i])
	{
		cout << min(dp0[i], dp1[i]) << endl;
		return;
	}
	else
	{
		cout << dp0[i] - 1 << endl;
		return;
	}
	if (!DEBUG)
	{
		return;
	}
	cout << "Answer 0 : ";
	for (i = 0; i < s.size(); i++)
	{
		cout << dp0[i] << " ";
	}
	cout << endl << "Answer 1 : ";
	for (i = 0; i < s.size(); i++)
	{
		cout << dp1[i] << " ";
	}

}
```
