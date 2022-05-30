int n, m, t, N, K, itemp1, itemp2, itemp3;
string s[31];

void solution() {
	int i, j, k;
	for ( i = 0; i < n; i++)
	{
		for ( j = 0; j < n; j++)
		{
			if (s[i][j] == '.')
			{
				continue;
			}
			char ctemp = s[i][j];
			if (i <= n - 3 && j >= 2)
			{
				bool winner = true;
				for (k = 1; k < 3; k++)
				{
					if (s[i + k][j - k] != ctemp)
					{
						winner = false;
						break;
					}
				}
				if (winner)
				{
					cout << ctemp;
					return;
				}
			}
			if (i <= n - 3 && j <= n - 3)
			{
				bool winner = true;
				for ( k = 1; k < 3; k++)
				{
					if (s[i+k][j+k] != ctemp)
					{
						winner = false;
						break;
					}
				}
				if (winner)
				{
					cout << ctemp;
					return;
				}
			}
			if (i <= n - 3)
			{
				bool winner = true;
				for (k = 1; k < 3; k++)
				{
					if (s[i + k][j] != ctemp)
					{
						winner = false;
						break;
					}
				}
				if (winner)
				{
					cout << ctemp;
					return;
				}
			}
			if (j <= n - 3)
			{
				bool winner = true;
				for (k = 1; k < 3; k++)
				{
					if (s[i][j + k] != ctemp)
					{
						winner = false;
						break;
					}
				}
				if (winner)
				{
					cout << ctemp;
					return;
				}
			}
		}
	}
	cout << "ongoing";
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
	cin >> n;
	for ( i = 0; i < n; i++)
	{
		cin >> s[i];
	}
}
