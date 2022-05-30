int t, n, m, input1, input2;
vector<vector<int>> network;
vector<vector<int>> personal;
void bfs(int member) {
	vector<bool> visited(n + 1);
	queue<pii> q;
	int i, j, k;
	q.push(pii(member, 0));
	while (!q.empty())
	{
		pii top = q.front();
		q.pop();
		int topIndex = top.first;
		int value = top.second;
		if (!visited[topIndex])
		{
			visited[topIndex] = 1;
			personal[member][topIndex] = value;
			for (i = 0; i < network[topIndex].size(); i++)
			{
				q.push(pii(network[topIndex][i], value + 1));
			}
		}
	}
}
int main() {
	//init
	FastIO;
	cin >> n;
	int i, j, k;
	network.resize(n+1);
	personal.resize(n+1);
	vector<int> vtemp(n + 1, 987654321);
	for (i = 1; i < n + 1; i++) { personal[i] = vtemp; }
	while (true)
	{
		cin >> input1 >> input2;
		if (input1 == -1 && input2 == -1){break;}
		network[input1].push_back(input2);
		network[input2].push_back(input1);
	}
	for (i = 1; i < n + 1; i++) {
		bfs(i);
	}
	vector<int> v;
	v.push_back(100);
	int score = 100;
	for ( i = 1; i < n + 1; i++)
	{
		int count = 0;
		for ( j = 1; j < n + 1; j++)
		{
			if (personal[i][j] > count)
			{
				count = personal[i][j];
			}
		}
		if (score > count)
		{
			score = count;
		}
		v.push_back(count);
	}
	set<int> s;
	for (i = 1; i < n + 1; i++)
	{
		if (v[i]==score)
		{
			s.insert(i);
		}
	}
	cout << score << " " << s.size() << endl;
	for (auto iter = s.begin(); iter != s.end(); iter++)
	{
		cout << *iter << " ";
	}
	return 0;
}
