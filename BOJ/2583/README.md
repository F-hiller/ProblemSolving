[2583번: 영역 구하기](https://www.acmicpc.net/problem/2583)

## 사고의 흐름

비어있는 영역을 구하는 그래프 탐색 문제였다. bfs방식을 사용하여 풀었으며 직사각형의 범위가 100*100의 작은 범위로 주어져서 별다른 수학적 식이나 논리 없이 직사각형 범위안의 모든 좌표들을 for문으로 하나씩 표시해줬다. 

또한 하나의 모눈 종이 칸에서 왼쪽 아래 모서리의 좌표를 해당 칸의 좌표라고 가정하였다. 즉, (0, 0) (0, 1) (1, 0) (1, 1)로 이루어진 모눈종이의 칸 하나를 (0, 0) 좌표로 가정하였다는 뜻이다.

```cpp
int i, j, k, n, m, t, itemp1, itemp2;
int K, itemp3, itemp4;
bool visited[100][100];
pii p1[100], p2[100];
vector<int> result;
void solution(int y, int x) {
	int i, j, k;
	int area = 0;

	queue<pii> q;
	q.push(pii(y, x));

	while (!q.empty())
	{
		pii top = q.front();
		q.pop();
		int topY = top.first;
		int topX = top.second;
		if (-1 < topY&&topY < n&&-1 < topX&&topX < m && !visited[topY][topX])
		{
			visited[topY][topX] = 1;
			area++;
			q.push(pii(topY + 1, topX));
			q.push(pii(topY, topX + 1));
			q.push(pii(topY, topX - 1));
			q.push(pii(topY - 1, topX));
		}
	}
	result.push_back(area);
}

int main() {
	//init
	FastIO;
	//init
	init();

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (!visited[i][j])
			{
				solution(i, j);
			}
		}
	}

	sort(result.begin(), result.end());

	cout << result.size() << endl;
	for (i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}

	return 0;
}

void init() {
	int i, j, k;
	cin >> n >> m >> K;
	for (i = 0; i < K; i++)
	{
		cin >> itemp1 >> itemp2 >> itemp3 >> itemp4;
		itemp3--;
		itemp4--;
		for (j = itemp1; j <= itemp3; j++)
		{
			for (k = itemp2; k <= itemp4; k++)
			{
				visited[k][j] = 1;
			}
		}
	}
}
```
