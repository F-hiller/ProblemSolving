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
