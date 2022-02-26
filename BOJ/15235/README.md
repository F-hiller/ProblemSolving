[15235번: Olympiad Pizza](https://www.acmicpc.net/problem/15235)

### 사고의 흐름

큐를 이용한 구현 문제로 큐에 모든 입력을 순서대로 집어넣고 하나씩 빼면서 해당 값이 1이면 현재의 시간을 정답 배열에 기록하고 1이 아니면 해당 값에 1을 뺀 값을 다시 큐에 넣는다.

큐가 빌 때까지 진행하며 끝이나면 정답을 기록한 배열을 출력해준다.

```cpp
	cin >> n;
	queue<pii> q;
	for ( i = 0; i < n; i++)
	{
		cin >> itemp;
		q.push(pii(i, itemp));
	}
	int t = 1;
	while (!q.empty())
	{
		pii front_value = q.front();
		q.pop();
		if (front_value.second != 1)
		{
			q.push(pii(front_value.first, front_value.second - 1));
		}
		else
		{
			ans[front_value.first] = t;
		}
		t++;
	}
	for ( i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}
```
