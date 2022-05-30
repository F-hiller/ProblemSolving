int n, m, t, itemp1, itemp2;
int K;
int truth[50];
bool isConnected[51][51];
vector<vector<int>> party;
vector<int> vtemp;
bool visited[51];

void bfs(int person) {
	int i, j, k;
	queue<int> q;
	q.push(person);
	while (!q.empty())
	{
		int value = q.front();
		q.pop();
		if (!visited[value])
		{
			visited[value] = 1;
			for ( i = 1; i < 51; i++)
			{
				if (isConnected[value][i])
				{
					q.push(i);
				}
			}
		}
	}
}

void solution() {
	int i, j, k;
	for ( i = 0; i < K; i++)
	{
		bfs(truth[i]);
	}
	int minus_party = 0;
	for ( i = 0; i < party.size(); i++)
	{
		for ( j = 0; j < party[i].size(); j++)
		{
			if (visited[party[i][j]])
			{
				minus_party--;
				break;
			}
		}
	}
	cout << m + minus_party;
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
	cin >> n >> m >> K;
	for ( i = 0; i < K; i++)
	{
		cin >> truth[i];
	}
	for ( i = 0; i < m; i++)
	{
		cin >> itemp1;
		for ( j = 0; j < itemp1; j++)
		{
			cin >> itemp2;
			vtemp.push_back(itemp2);
		}
		party.push_back(vtemp);
		vtemp.clear();
		for ( j = 0; j < itemp1; j++)
		{
			for ( k = j+1; k < itemp1; k++)
			{
				isConnected[party[i][j]][party[i][k]] = 1;
				isConnected[party[i][k]][party[i][j]] = 1;
			}
		}
	}
}
