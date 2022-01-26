[2638번: 치즈](https://www.acmicpc.net/problem/2638)

### 사고의 흐름

그래프 탐색 문제에 구현을 섞은 문제이다. 구현을 하는 과정에서 코드가 길어졌다. 

3가지 단계로 문제를 진행했다.

1. 외부 공기 여부 확인
2. 치즈 녹이기
3. 다 녹았는지 확인하기

(1. 외부 공기 여부 확인)

맨 가장자리에는 치즈 올 수 없다는 문제조건이 있으므로 위치상 무조건 외부공기가 된다.

여기서부터 외부공기와 닿는(bfs로 만나는) 모든 치즈가 아닌 위치는 외부공기가 된다. 이를 통해 외부 공기 여부를 확인해주고 isAir라는 bool형 2차원 배열에 체크해준다.

(2. 치즈 녹이기)

이중 for문을 통해 모든 칸을 확인하면서 치즈의 4방향에 외부 공기가 몇개인지 확인해주고 녹아 없어질 치즈면 바로 없애지 말고 isMelt bool형 2차원 배열에 체크해준다. 만약 바로 치즈를 없애버리면 녹지않을 동시간대의 옆 치즈가 녹는다고 판정할 수도 있다.

반복문이 끝났으면 다시 돌면서 isMelt의 값이 true인 위치의 치즈를 녹여준다.

(3. 다 녹았는지 확인하기)

말그대로 이중 for문을 돌면서 치즈가 하나라도 존재하는 확인해준다.

```cpp
int n, m, t, N, K, itemp1, itemp2, itemp3;
int arr[101][101];
bool isAir[101][101];
bool isMelt[101][101];

void print_arr() {
	int i, j, k;
	cout << endl << "==============================" << endl;
	for ( i = 0; i < n; i++)
	{
		for ( j = 0; j < m; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << "==============================" << endl;
}

void isMelt_clear() {
	int i, j, k;
	for ( i = 0; i < n; i++)
	{
		for ( j = 0; j < m; j++)
		{
			isMelt[i][j] = 0;
		}
	}
}

void airSelect(int y, int x) {
	int i, j, k;
	queue<pii> q; 
	for (i = 0; i < 4; i++)
	{
		q.push(pii(y + dirY[i], x + dirX[i]));
	}
	while (!q.empty())
	{
		pii top = q.front();
		q.pop();
		int topY = top.first;
		int topX = top.second;
		if (-1 < topY&&topY < n&&-1 < topX&&topX < m && !isAir[topY][topX] && !arr[topY][topX])
		{
			isAir[topY][topX] = 1;
			for ( i = 0; i < 4; i++)
			{
				q.push(pii(topY + dirY[i], topX + dirX[i]));
			}
		}
	}
}

void setAir() {
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (isAir[i][j])
			{
				airSelect(i, j);
			}
		}
	}

}

void cheeseMelt() {
	int i, j, k;
	int count = 0;
	for ( i = 0; i < n; i++)
	{
		for ( j = 0; j < m; j++)
		{
			if (!arr[i][j])
			{
				continue;
			}
			count = 0;
			for (k = 0; k < 4; k++)
			{
				if (isAir[i+dirY[k]][j+ dirX[k]])
				{
					count++;
				}
			}
			if (count > 1)
			{
				isMelt[i][j] = 1;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (isMelt[i][j])
			{
				arr[i][j] = 0;
			}
		}
	}
	isMelt_clear();
}

bool meltCheck() {
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (arr[i][j] == 1)
			{
				return false;
			}
		}
	}
	return true;
}

void solution() {
	int i, j, k;
	int t = 1;
	while (true)
	{
		setAir();
		cheeseMelt();
		if (DEBUG)
		{
			print_arr();
		}
		if (meltCheck())
		{
			break;
		}
		t++;
	}
	cout << t;
}

int main() {
	//init
	FastIO;
	//init
	int i, j, k;
	init();

	solution();

	return 0;
}

void init() {
	int i, j, k;
	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	isAir[0][0] = 1;
	isAir[0][m - 1] = 1;
	isAir[n - 1][0] = 1;
	isAir[n - 1][m - 1] = 1;
}
```
