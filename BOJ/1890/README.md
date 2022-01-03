[1890번: 점프](https://www.acmicpc.net/problem/1890)

## 사고의 흐름

처음에는 dfs문제로 생각하고 진행하였다. 하지만 나올 수 있는 길의 수가 2^63-1이하라는 점에서 dfs는 시간초과가 생길 수 밖에 없었다. 어느 특정 위치에 도착하면 종착점으로 갈 수 있는 방법의 갯수는 정해져있다. 이를 계산하는 과정을 줄이기 위해서 dp 배열을 사용했고 2가지 방법으로 풀었다. 다음 위치에 현재 위치까지의 경우의 수를 더해주는 방법과 현재 위치에서 이전 위치까지의 경우의 수를 더해주는 방법을 썼다. 하지만 후자의 경우 논리가 직관적이지 않아서 코드는 전자의 내용으로 올렸다. 

```cpp
int n, m, itemp1, itemp2, itemp3;
int arr[100][100];
ll cnt_arr[100][100];

void solve() {
	int i, j, k, l;
	cnt_arr[0][0] = 1;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == n-1 && j == n-1)
			{
				break;
			}
			if (j + arr[i][j] < n)
			{
				cnt_arr[i][j + arr[i][j]] += cnt_arr[i][j];
			}
			if (i + arr[i][j] < n)
			{
				cnt_arr[i + arr[i][j]][j] += cnt_arr[i][j];
			}
		}
	}
	cout << cnt_arr[n - 1][n - 1];
}

int main() {
	//init
	FastIO;
	int i, j, k;

	//input
	init();

	//solve problem
	solve();

	return 0;
}
void init() {
	int i, j, k;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
}
```
