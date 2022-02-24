[11944번: NN](https://www.acmicpc.net/problem/11944)

## 사고의 흐름

쉬운 문제였지만 문자열과 숫자를 구분하는 과정에서 조금 헷갈려했다. 

문제에서 답이 길어지는 경우 앞의 m자리만 출력한다고 제시되어있는데 당연한 이야기이지만 이는 출력할 문자열이 m보다 클 경우 m자리만 출력해주면 된다. 

n을 n번 출력하면 문자열의 전체 길이가 ( n의 자릿수 * n )임을 이용해서 풀어주면 된다.

```cpp
	int cnt = 0;
	//solution
	string stemp;
	cin >> n >> m;
	stemp = to_string(n);
	itemp = n;
	while (itemp)
	{
		itemp /= 10;
		cnt++;
	}
	if (cnt * n <= m)
	{
		for (i = 0; i < n; i++)
		{
			cout << n;
		}
		return 0;
	}
	for (i = 0; i < m / cnt; i++)
	{
		cout << n;
	}
	for (i = 0; i < m % cnt; i++)
	{
		cout << stemp[i];
	}
```
