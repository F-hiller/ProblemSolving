[5014번: 스타트링크](https://www.acmicpc.net/problem/5014)

## 사고의 흐름

bfs 그래프 탐색 문제로 주의 해야할 점은 U층 위, 또는 D층 아래에 해당하는 층이 없을 때는, 엘리베이터는 움직이지 않는다는 점이다. 

늘 이야기하지만 bfs로 어떤 점을 방문했을 때가 해당 정점으로 방문할 수 있는 최단 횟수이다. 가중치에 관한 말이 나온다면 해당 내용을 배열에 저장하는 것을 고려해야하지만 그러한 유형이 아니라면 bool형 배열 visited로 선언하고 진행해야한다. 

```cpp
//additional variables
bool visited[1000000];

//main function
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//init
	int i, j, k;
	int f, s, g, u, d;
	//solution
	cin >> f >> s >> g >> u >> d;
	queue<pii> q;
	q.push(pii(s, 0));
	while (!q.empty())
	{
		pii top = q.front();
		q.pop();
		int index = top.first;
		int value = top.second;
		if (index < 1 || index > f || visited[index])
		{
			continue;
		}
		if (index == g)
		{
			cout << value;
			return 0;
		}
		visited[index] = 1;
		q.push(pii(index + u, value + 1));
		q.push(pii(index - d, value + 1));
	}
	cout << "use the stairs";
	return 0;
}
```
