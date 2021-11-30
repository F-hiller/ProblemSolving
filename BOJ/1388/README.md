[1388번: 바닥 장식](https://www.acmicpc.net/problem/1388)

## 사고의 흐름

bfs문제인 것 같은데 정작 그렇게 풀지 못했다.

탐색 범위도 50*50으로 작았고 -판자면 오른쪽 모든 범위를 확인하고, |판자면 아래쪽 모든 범위를 확인하여 visited에 표시하는 방식으로 진행하였다.

```cpp
int t, n, m, input1, input2;
string arr[51];
bool visited[51][51];

void solution() {
	int result = 0;
	int i, j, k;
	for ( i = 0; i < n; i++)
	{
		for ( j = 0; j < m; j++)
		{
			if (!visited[i][j])
			{
				int y = i;
				int x = j;

				visited[i][j] = 1;

				result++;

				if (arr[i][j] == '-')
				{
					x++;
					while (x < m && arr[i][x] == '-' && !visited[i][x])
					{
						visited[i][x] = 1;
						x++;
					}
				}
				else
				{
					y++;
					while (y < n && arr[y][j] == '|' && !visited[y][j])
					{
						visited[y][j] = 1;
						y++;
					}
				}
			}
		}
	}
	cout << result;
}

int main() {
	//init
	FastIO;
	int i, j, k;
	cin >> n >> m;
	for ( i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	solution();

	return 0;
}
```
