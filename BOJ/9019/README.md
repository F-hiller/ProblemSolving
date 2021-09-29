[9019번: DSLR](https://www.acmicpc.net/problem/9019)

## 사고의 흐름

아직까지도 bfs를 제대로 이해하지 못하고 있었다.

bfs를 통해 방문한 노드는 항상 최단 거리를 가진다. 

즉 bfs 도중 end 노드를 만나면 거기서 break를 통해 끝내야 한다는 것이다.

방문한 노드는 가장 짧은 경로가 이미 기록 되어있기에 visited 배열로 항상 확인해줘야한다.

```cpp
int t, n, m, a, b, c, d, e, itemp1, itemp2;
typedef pair<pii, char> piii;
piii arr[10000];
bool visited[10000];

int left(int cur) { return (cur * 10) % 10000 + (cur / 1000); }
int right(int cur) { return (cur / 10) + (cur % 10) * 1000; }
void print_result(int end) {
	int cur = end;
	int pre = arr[cur].first.first;
	stack<char> s;
	while (pre != cur)
	{
		s.push(arr[cur].second);
		cur = pre;
		pre = arr[cur].first.first;
	}
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
	cout << endl;
}
void solution(int start, int end) {
	queue<piii> q;
	q.push(piii(pii(start, start), 'X'));
	while (!q.empty())
	{
		piii top = q.front();
		q.pop();
		int pre = top.first.first;
		int cur = top.first.second;
		if (!visited[cur])
		{
			if (pre == end)
			{
				break;
			}
			arr[cur] = top;
			visited[cur] = 1;
			//D
			q.push(piii(pii(cur, (2 * cur) % 10000), 'D'));
			//S
			q.push(piii(pii(cur, (cur + 9999) % 10000), 'S'));
			//L
			q.push(piii(pii(cur, left(cur)), 'L'));
			//R
			q.push(piii(pii(cur, right(cur)), 'R'));
		}
	}
	print_result(end);
}
int main() {
	//init
	FastIO;
	int i, j;
	cin >> t;
	for (i = 0; i < t; i++)
	{
		cin >> itemp1 >> itemp2;
		for (j = 0; j < 10000; j++) { visited[j] = 0; }
		solution(itemp1, itemp2);
	}
	return 0;
}
```
