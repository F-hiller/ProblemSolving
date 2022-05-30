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
