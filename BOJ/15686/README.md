[](https://www.acmicpc.net/problem/15686)

## 사고의 흐름

짜다보니 코드가 길어져서 아쉽다. 

저번에 이 문제를 시도했었는데 그 때는 집에서 bfs를 하면서 치킨거리를 구하려고 했다. 저장해야할 내용도 많았고 생각이 꼬여서 그만뒀었다. 

이번에 새로 시도하면서는 치킨집에서부터 bfs 를 통해 치킨거리를 구해보았다. 그리고 착각한 것이 있었는데 bfs를 한다고 해서 실제로 길찾기를 하려는 것은 아니라는 점이다. bfs를 하는 이유는 치킨집과 집 사이의 치킨 거리를 구하기 위해 진행하는 것이므로 해당 경로에 건물이 있어서 bfs가 멈추는 경우는 발생하지 않는다.

과정은 글로 적으면 생각보다 간단하다.

1. 치킨집 x개를 고른다. ( x≤m )
2. 고른 치킨집에서 bfs를 이용해 도시의 치킨거리를 구한다.
3. 모든 경우를 실행해보고 치킨 거리가 가장 작은 값을 출력한다.

코드 제출하기 전에 오류가 생겨서 한참을 디버깅했는데 아무 문제가 없어서 다시 돌려보니까 잘 돌아가서 조금 마음이 아팠다..

```cpp
typedef pair<pii, int> piii;
int t, n, m, a, b, c, d, e, itemp1, itemp2;
int result = 987654321;
vector<int> vtemp;
vector<vector<int>> arr;

vector<bool> visitedTemp;
vector<vector<bool>> visited;

vector<pii> chicken;
vector<bool> chickenCheck;

void bfs() {
	queue<piii> q;
	int resultValue = 0;
	int i, j, k;
	for (i = 0; i < chicken.size(); i++)
	{
		if (chickenCheck[i])
		{
			q.push(piii(chicken[i], 0));
		}
	}
	while (!q.empty())
	{
		piii top = q.front();
		q.pop();
		int topY = top.first.first;
		int topX = top.first.second;
		int topValue = top.second;
		if (((-1 < topY&&topY < n) && (-1 < topX&&topX < n)) && !visited[topY][topX])
		{
			visited[topY][topX] = 1;
			q.push(piii(pii(topY + 1, topX), topValue + 1));
			q.push(piii(pii(topY - 1, topX), topValue + 1));
			q.push(piii(pii(topY, topX + 1), topValue + 1));
			q.push(piii(pii(topY, topX - 1), topValue + 1));
			if (arr[topY][topX] == 1)
			{
				resultValue += topValue;
				if (resultValue > result)
				{
					while (!q.empty()){q.pop();}
					for (i = 0; i < n; i++) { for (j = 0; j < n; j++) { visited[i][j] = 0; } }
					return;
				}
			}
		}
	}
	if (result > resultValue)
	{
		result = resultValue;
	}
	for (i = 0; i < n; i++) { 
		for (j = 0; j < n; j++) { 
			visited[i][j] = 0; 
		} 
	}
}
void solution(int depth, int select, int num) {
	if (select == num)
	{
		bfs();
		return;
	}
	if (depth == chicken.size())
	{
		return;
	}
	chickenCheck[depth] = 1;
	solution(depth + 1, select + 1, num);
	chickenCheck[depth] = 0;
	solution(depth + 1, select, num);
}
int main() {
	//init
	FastIO;
	cin >> n >> m;
	int i, j, k;
	vtemp.resize(n);
	visitedTemp.resize(n);
	for (i = 0; i < n; i++)
	{
		arr.push_back(vtemp);
		visited.push_back(visitedTemp);
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j]==2)
			{
				chicken.push_back(pii(i, j));
				chickenCheck.push_back(0);
			}
		}
	}

	for (i = 1; i <= m; i++)
	{
		solution(0, 0, i);
	}

	cout << result;

	return 0;
}
```
