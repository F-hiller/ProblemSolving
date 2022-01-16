[12851번: 숨바꼭질 2](https://www.acmicpc.net/problem/12851)

## 사고의 흐름

가장 빠르게 도달할 수 있는 방법에 대해 묻는 문제이므로 bfs를 통해 해결했다. 하지만 추가적으로 가장 빠른 시간으로 도착할 수 있는 방법의 수를 추가적으로 묻기 때문에 이 부분을 더 생각해줘야했다. 

bfs를 통해 목적지에 처음 도착할 때의 시간이 가장 빠른 시간(result)이다. 큐의 뒤에 들어온 값들은 앞에 있는 값과 동시에, 또는 나중에 들어온 값들이므로 큐에 들어있는 경로들의 시간은 result의 시간과 같거나 크다. 따라서 큐에 남아있는 값들을 모두 탐색하지만 다시 큐에 넣는 작업(q.push())는 진행하지 않는다. 이렇게 하면 목적지를 가장 빠른 시간에 도착하는 방법들 모두를 확인해볼 수 있다.

```jsx
int n, m, t, N, K, itemp1, itemp2;
int visited[SHARING];
int result = 0;
int cnt = 0;

void solution() {
	int i, j, k;
	bool first_check = 0;
	queue<pii> q;
	q.push(pii(N, 1));
	while (!q.empty())
	{
		pii top = q.front();
		q.pop();
		int index = top.first;
		int value = top.second;
		if (index == K)
		{
			if (!first_check)
			{
				first_check = 1;
				result = value;
				cnt++;
				continue;
			}
			if (result > value)
			{
				cnt = 1;
				result = value;
				continue;
			}
			if (result == value)
			{
				cnt++;
			}
			continue;
		}
		if (first_check)
		{
			continue;
		}
		if (-1 < index && index < SHARING && (visited[index] == 0 || visited[index] >= value))
		{
			visited[index] = value;
			q.push(pii(index + 1, value + 1));
			q.push(pii(index - 1, value + 1));
			q.push(pii(index * 2, value + 1));
		}
	}
}

int main() {
	//init
	FastIO;
	//init
	int i, j, k;
	init();

	solution();

	cout << result - 1 << endl << cnt;

	return 0;
}

void init() {
	int i, j, k;
	cin >> N >> K;
}
```
