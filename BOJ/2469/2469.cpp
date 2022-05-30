int n, m, t, itemp1, itemp2;
string down_top, result;
string ladder[1000];
char top_down[26];
char ctemp;

void solution() {
	int i, j, k;
	//top to down
	for ( i = 0; i < m; i++)
	{
		if (ladder[i][0]=='?')
		{
			break;
		}
		for ( j = 0; j < n - 1; j++)
		{
			if (ladder[i][j] == '*')
			{
				continue;
			}
			ctemp = top_down[j];
			top_down[j] = top_down[j + 1];
			top_down[j + 1] = ctemp;
		}
	}
	//down to top
	for ( i = m - 1; i > -1; i--)
	{
		if (ladder[i][0] == '?')
		{
			break;
		}
		for (j = 0; j < n - 1; j++)
		{
			if (ladder[i][j] == '*')
			{
				continue;
			}
			ctemp = down_top[j];
			down_top[j] = down_top[j + 1];
			down_top[j + 1] = ctemp;
		}
	}
	//compare top_down and down_top
	//cout << top_down << endl << down_top << endl;
	for ( i = 0; i < n - 1; i++)
	{
		if (top_down[i] == down_top[i])
		{
			result.push_back('*');
			continue;
		}
		if (top_down[i] == down_top[i+1]&&top_down[i+1] == down_top[i])
		{
			ctemp = down_top[i];
			down_top[i] = down_top[i + 1];
			down_top[i + 1] = ctemp;
			result.push_back('-');
			continue;
		}
		for ( i = 0; i < n - 1; i++)
		{
			cout << 'x';
		}
		return;
	}
	cout << result;
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
	cin >> down_top;
	for ( i = 0; i < m; i++)
	{
		cin >> ladder[i];
	}
	for ( i = 0; i < n; i++)
	{
		top_down[i] = i + 'A';
	}
}
