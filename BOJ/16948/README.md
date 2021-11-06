[16948번: 데스 나이트](https://www.acmicpc.net/problem/16948)

## 사고의 흐름

bfs문제이다.

```cpp
int t, n, m, input1, input2;
int r1, c1, r2, c2;
int visited[200][200];
void bfs() {
	int i, j, k;
	queue<piii> q;
	q.push(piii(pii(r1, c1), 0));
	while (!q.empty())
	{
		piii top = q.front();
		q.pop();
		int topY = top.first.first;
		int topX = top.first.second;
		int value = top.second;
		if ((-1 < topY&&topY < n&&-1 < topX&&topX < n) && !visited[topY][topX])
		{
			visited[topY][topX] = 1;
			if (topY == r2 && topX == c2)
			{
				cout << value;
				exit(0);
			}
			q.push(piii(pii(topY - 2, topX - 1), value + 1));
			q.push(piii(pii(topY - 2, topX + 1), value + 1));
			q.push(piii(pii(topY, topX - 2), value + 1));
			q.push(piii(pii(topY, topX + 2), value + 1));
			q.push(piii(pii(topY + 2, topX - 1), value + 1));
			q.push(piii(pii(topY + 2, topX + 1), value + 1));
		}
	}
	cout << -1;
}

int main() {
	//init
	FastIO;
	int i, j, k;
	cin >> n >> r1 >> c1 >> r2 >> c2;

	bfs();

	return 0;
}
```
