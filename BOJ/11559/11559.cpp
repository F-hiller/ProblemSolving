int i, j, k, n, m, itemp1, itemp2, itemp3;
string s[12];
bool visited[12][6] = { 0, };
int result = 0;

void print_result() {
	cout << "=======================\n";
	for (i = 0; i < 12; i++)
	{
		cout << s[i] << endl;
	}
	cout << "=======================\n";
}
void visit_clear() {
	for ( i = 0; i < 12; i++)
	{
		for ( j = 0; j < 6; j++)
		{
			visited[i][j] = 0;
		}
	}
}

bool boom(int i, int j) {
	queue<pii> q;
	stack<pii> stk;
	q.push(pii(i, j));
	char block = s[i][j];
	int cnt = 0;
	while (!q.empty())
	{
		pii top = q.front();
		q.pop();
		int topY = top.first;
		int topX = top.second;
		if ((-1 < topY && topY < 12 && -1 < topX && topX < 6) && !visited[topY][topX] && s[topY][topX] == block)
		{
			cnt++;
			visited[topY][topX] = 1;
			stk.push(pii(topY, topX));
			q.push(pii(topY+1, topX));
			q.push(pii(topY-1, topX));
			q.push(pii(topY, topX+1));
			q.push(pii(topY, topX-1));
		}
	}
	if (cnt > 3)
	{
		while (!stk.empty())
		{
			pii top = stk.top();
			stk.pop();
			s[top.first][top.second] = '.';
		}
		return 1;
	}
	return 0;
}
void gravity() {
	for ( i = 0; i < 6; i++)
	{
		int height = 0;
		for ( j = 11; j > -1; j--)
		{
			if (s[j][i] != '.')
			{
				for ( k = j+1; k < 12; k++)
				{
					if (s[k][i] != '.')
					{
						break;
					}
				}
				s[k-1][i] = s[j][i];
				if (j != k - 1)
				{
					s[j][i] = '.';
				}
			}
		}
	}
	return;
}
void simulation() {
	bool boom_check;
	while (true)
	{
		gravity();
		boom_check = 0;
		for ( i = 0; i < 12; i++)
		{
			for ( j = 0; j < 6; j++)
			{
				if (s[i][j] != '.' && boom(i, j))
				{
					boom_check = 1;
				}
			}
		}
		//print_result();
		visit_clear();
		if (boom_check)
		{
			result++;
			continue;
		}
		return;
	}
}

int main() {
	//init
	FastIO;
	//input
	for ( i = 0; i < 12; i++)
	{
		cin >> s[i];
	}

	simulation();

	cout << result;

	return 0;
}
