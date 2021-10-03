[13549번: 숨바꼭질 3](https://www.acmicpc.net/problem/13549)

## 사고의 흐름

bfs문제를 파악하고 풀었다. 하지만 문제가 있었다. 

bfs를 진행할 때 원래의 경우에는 방문한 곳이 목적지라면 항상 최선의 값을 가진다고 가정했었는데 이번에는 순간이동을 한다면 시간을 소모하지 않기에 나중에 방문하더라도 최선의 값이 될 수 있었다. 그래서 visited 배열보다는 방문했을 때의 시간이 이전 시간 기록보다 작으면 bfs를 이어나가는 방식으로 진행하였다. 

ex) 

5 17 이라면

5에서 4, 6을 가는 비용이 1

10을 가는 비용이 0이다. 

그 후 4에서 3, 5, 8

6에서 5, 7, 12를 가고 

10에서 9, 11, 20을 간다.

이 때 결과를 정리해보자면 

5 : 0

4 : 1

6 : 1

10 : 0

3 : 2

8 : 1

7 : 2

12 : 1

9 : 1

11 : 1

20 : 0 이다. 20은 bfs 과정에서 가장 나중에 나온 수임에도 0으로 최선의 값을 가지고 있다.

```cpp
int t, n, m, a, b, c, d, e, itemp1, itemp2;
int k;
int arr[100001];

void solution() {
	queue<pii> q;
	q.push(pii(n, 0));
	while (!q.empty())
	{
		pii front = q.front();
		int index = front.first;
		int value = front.second;
		q.pop();
		if ((-1 < index && index < 100001) && value < arr[index])
		{
			arr[index] = value;
			q.push(pii(index + 1, value + 1));
			q.push(pii(index - 1, value + 1));
			q.push(pii(2 * index, value));
		}
	}
}

int main() {
	//init
	FastIO;
	int i;
	for (i = 0; i < 100001; i++) { arr[i] = 987654321; }
	cin >> n >> k;

	solution();

	cout << arr[k];

	return 0;
}
```
