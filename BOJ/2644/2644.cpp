int n, m, itemp1, itemp2, itemp3;
int a, b;
vector<int> v[100];
bool visited[100];

void solution() {
	int i, j, k;
	queue<pii> s;
	s.push(pii(a, 0));
	while (!s.empty())
	{
		pii top = s.front();
		int index = top.first;
		int num = top.second;
		s.pop();
		if (visited[index])
		{
			continue;
		}
		visited[index] = 1;
		if (index == b)
		{
			cout << num;
			return;
		}
		for (i = 0; i < v[index].size(); i++)
		{
			s.push(pii(v[index][i], num+1));
		}
	}
	cout << -1;
}

int main() {
	//init
	FastIO;
	int i, j, k;

	//input
	init();

	solution();

	return 0;
}
void init() {
	int i, j, k;
	cin >> n >> a >> b >> m;
	for (i = 0; i < m; i++)
	{
		cin >> itemp1 >> itemp2;
		v[itemp1].push_back(itemp2);
		v[itemp2].push_back(itemp1);
	}
}
