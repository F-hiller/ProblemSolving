int n, m, t, itemp1, itemp2;
char arr[3072][6144];

void solution(int y, int x, int len) {
	if (len == 3)
	{
		arr[y][x] = '*';
		arr[y+1][x-1] = '*';
		arr[y+1][x+1] = '*';
		for (int i = 0; i < 5; i++)
		{
			arr[y + 2][x - 2 + i] = '*';
		}
		return;
	}
	int half_len = len / 2;
	solution(y, x, half_len);
	solution(y + half_len, x + half_len, half_len);
	solution(y + half_len, x - half_len, half_len);
}

int main() {
	//init
	FastIO;
	//init
	int i, j, k;
	init();

	solution(0, n-1, n);

	for ( i = 0; i < n; i++)
	{
		for ( j = 0; j < 2 * n; j++)
		{
			if (arr[i][j] == NULL)
			{
				cout << " ";
				continue;
			}
			cout << arr[i][j];
		}
		cout << endl;
	}

	return 0;
}

void init() {
	int i, j, k;
	cin >> n;
}
