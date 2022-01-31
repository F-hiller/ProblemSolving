[Problem - A - Codeforces](https://codeforces.com/contest/1633/problem/A)

### 사고의 흐름

최소한의 자릿수만 바꿔서 7로 나누어 떨어지게 만드는 문제이다.

만약 7로 나누어 떨어지지 않는다면 1의 자리 수를 바꾸면 반드시 7로 나누어떨어지게 되있다. 따라서 for문 돌면서 직접 다 확인해봤다.

```bash
void solution() {
	int i, j, k;
	if (n % 7 == 0)
	{
		cout << n << endl;
		return;
	}
	n -= n - n / 10 * 10;
	for (i = 0; i < 10; i++)
	{
		if ((n + i) % 7 == 0)
		{
			cout << n + i << endl;
			return;
		}
	}
}
```
