[14867번: 물통](https://www.acmicpc.net/problem/14867)

## 사고의 흐름

그래프 탐색 문제로 a, b의 범위가 1000인 경우 2차원 배열을 통해서 해결할 수 있었다.

하지만 10만*10만=100억의 범위로 확장되는 순간 2차원 배열을 사용할 수 없다.

어떤 수학적 방식으로 해결할 수 있을 지에 대해서 생각해봤지만 정답은 map 자료구조를 사용하는 것이었다.

고정된 배열을 사용하는 것은 분명 빠르고 예상된 범위안에서 작동할 수 있지만 그렇다고 해서 map, set이 문제를 해결할 수 없을 정도로 느린 것도 아니다. 여러 자료구조들도 문제를 해결하는데 충분히 사용할 수 있다.

```cpp
int a, b, c, d;
map<pii, bool> visited;

void bfs() {
	int i, j;
	queue<piii> q;
	q.push(piii(pii(0, 0), 0));
	visited[pii(0, 0)] = 0;
	while (!q.empty())
	{
		piii front = q.front();
		q.pop();
		int a_cur = front.first.first;
		int b_cur = front.first.second;
		int value = front.second;
		if (a_cur == c && b_cur == d)
		{
			cout << value;
			return;
		}
		if (!visited[pii(a_cur, b_cur)])
		{
			visited[pii(a_cur, b_cur)] = 1;
			q.push(piii(pii(0, b_cur), value + 1));
			q.push(piii(pii(a_cur, 0), value + 1));
			q.push(piii(pii(a, b_cur), value + 1));
			q.push(piii(pii(a_cur, b), value + 1));
			if (a_cur + b_cur >= b)
			{
				q.push(piii(pii(a_cur - (b - b_cur), b), value + 1));
			}
			else
			{
				q.push(piii(pii(0, a_cur + b_cur), value + 1));
			}
			if (a_cur + b_cur >= a)
			{
				q.push(piii(pii(a, b_cur - (a - a_cur)), value + 1));
			}
			else
			{
				q.push(piii(pii(a_cur + b_cur, 0), value + 1));
			}
		}
	}
	cout << -1;
}

int main() {
	//init
	FastIO;
	int i, j, k;

	//solution
	cin >> a >> b >> c >> d;

	bfs();

	return 0;
}
```
