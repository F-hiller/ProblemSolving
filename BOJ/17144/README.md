[17144번: 미세먼지 안녕!](https://www.acmicpc.net/problem/17144)

## 사고의 흐름

구현을 하다보니 코드가 길어졌다.

미세먼지가 퍼지는 과정을 구현한 diffusion함수, 공기청정기에 의해 공기가 순환되는 과정을 구현한 circulation함수로 구성했다.

미세먼지가 퍼질 때 해당 시간의 다른 영역에는 영향을 줘서는 안되기에 diffuse_arr라는 배열을 만들어서 이곳에 퍼지는 정도를 반영했다. 예를 들어 미세먼지가 5인 칸 A가 있고 그 옆에 9인 칸 B가 있을 때 바로 반영을 하면 A칸이 옆의 칸들에게 영향줘서 B의 값이 10이 된다. 10이 된 B는 9였을 때의 미세먼지 전파 값 1이 아닌 2로 미세먼지를 전달하게 된다.

공기청정기의 순환은 그저 한쪽 벽에 닿을 때까지 x나 y값을 증가, 감소시키며 움직이면 된다.

```jsx
int n, m, t, N, K, itemp1, itemp2;
int arr[50][50];
int diffuse_arr[50][50];
int dirY[] = { -1, 0, 1, 0 };
int dirX[] = { 0, 1, 0, -1 };
pii pos_circular = pii(-1, -1);

void diffusion() {
	int i, j, k;
	int nextY, nextX;
	int value; //
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (arr[i][j] > 0)
			{
				value = arr[i][j] / 5;
				for (k = 0; k < 4; k++)
				{
					nextY = i + dirY[k];
					nextX = j + dirX[k];
					if (-1 < nextY && nextY < n&&-1 < nextX && nextX < m && arr[nextY][nextX] != -1)
					{
						diffuse_arr[i][j] -= value;
						diffuse_arr[nextY][nextX] += value;
					}
				}
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			arr[i][j] += diffuse_arr[i][j];
			diffuse_arr[i][j] = 0;
		}
	}
}
void circulation() {
	int i, j, k;
	int y1 = pos_circular.first;
	int y2 = y1 + 1;
	int x = 1;
	int circular_value1 = 0;
	int circular_value2 = 0;

	//우측으로 순환
	while (x != m)
	{
		itemp1 = arr[y1][x];
		arr[y1][x] = circular_value1;
		circular_value1 = itemp1;

		itemp2 = arr[y2][x];
		arr[y2][x] = circular_value2;
		circular_value2 = itemp2;
		x++;
	}
	x--;
	//위아래로 순환
	y1--;
	while (y1 != -1)
	{
		itemp1 = arr[y1][x];
		arr[y1][x] = circular_value1;
		circular_value1 = itemp1;
		y1--;
	}
	y1++;
	y2++;
	while (y2 != n)
	{
		itemp2 = arr[y2][x];
		arr[y2][x] = circular_value2;
		circular_value2 = itemp2;
		y2++;
	}
	y2--;
	//왼쪽으로 순환
	x--;
	while (x != -1)
	{
		itemp1 = arr[y1][x];
		arr[y1][x] = circular_value1;
		circular_value1 = itemp1;

		itemp2 = arr[y2][x];
		arr[y2][x] = circular_value2;
		circular_value2 = itemp2;
		x--;
	}
	x++;
	//위아래로 순환 후 한바퀴 완료
	y1++;
	while (y1 != pos_circular.first)
	{
		itemp1 = arr[y1][x];
		arr[y1][x] = circular_value1;
		circular_value1 = itemp1;
		y1++;
	}
	y1--;
	y2--;
	while (y2 != pos_circular.first+1)
	{
		itemp2 = arr[y2][x];
		arr[y2][x] = circular_value2;
		circular_value2 = itemp2;
		y2--;
	}
	y2++;
}

void show_result() {
	int i, j, k=0;
	for ( i = 0; i < n; i++)
	{
		for ( j = 0; j < m; j++)
		{
			if (arr[i][j] > 0)
			{
				k += arr[i][j];
			}
		}
	}
	cout << k;
}

void solution() {
	int i, j, k;
	for (i = 0; i < t; i++)
	{
		diffusion();
		//show_result();
		circulation();
		//show_result();
	}
	show_result();
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
	cin >> n >> m >> t;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == -1 && pos_circular.first == -1)
			{
				pos_circular.first = i;
				pos_circular.second = j;
			}
		}
	}
}
```
