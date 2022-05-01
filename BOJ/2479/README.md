[2479번: 경로 찾기](https://www.acmicpc.net/problem/2479)

## 사고의 흐름

bfs 문제이다.

처음에 문자 길이가 30인것을 보고 2^30가지의 경우를 어떻게 처리할 지에 대해 고민했다.

하지만 2^30에 달하는 모든 경우가 나오는 것이 아닌 N≤1000개의 경우가 나오므로 노드에서 노드로의 해밍 거리가 1로 존재하는지 for문을 통해 확인해보면 된다.

경로가 없다면 -1을 출력하는데, 경로가 있을 때 return이 아닌 break를 통해 구현하여서 틀렸었다.

```cpp

#define SHARING 1001

int n, m, t, N, K;

//additional variables
int visited[SHARING];
string s[SHARING];

void bfs(int start, int finish) {
	int i, j;
	queue<pii> q;

	q.push(pii(start, start));

	while (!q.empty())
	{
		pii top = q.front();
		q.pop();
		int index = top.first;
		int pre = top.second;

		if (index == finish)
		{
			stack<int> path;
			path.push(index);
			while (pre != index)
			{
				index = pre;
				pre = visited[pre];
				path.push(index);
			}
			while (!path.empty())
			{
				cout << path.top() << " ";
				path.pop();
			}
			return ;
		}
		if (0 < index&&index <= n && !visited[index])
		{
			visited[index] = pre;
			int cnt;
			for (i = 1; i <= n; i++)
			{
				cnt = 0;
				for (j = 0; j < K; j++)
				{
					if (s[index][j] != s[i][j])
					{
						cnt++;
						if (cnt >= 2)
						{
							break;
						}
					}
				}
				if (cnt == 1)
				{
					q.push(pii(i, index));
				}
			}
		}
	}
	cout << -1;
}

//main function
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//init
	int t, i, j, k, itemp;
	int start, finish;

	//solution
	cin >> n >> K;
	for (i = 1; i <= n; i++)
	{
		cin >> s[i];
	}
	cin >> start >> finish;

	bfs(start, finish);

	return 0;
}
```
