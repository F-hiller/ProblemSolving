//additional variables
bool visited[1000000];

//main function
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//init
	int i, j, k;
	int f, s, g, u, d;
	//solution
	cin >> f >> s >> g >> u >> d;
	queue<pii> q;
	q.push(pii(s, 0));
	while (!q.empty())
	{
		pii top = q.front();
		q.pop();
		int index = top.first;
		int value = top.second;
		if (index < 1 || index > f || visited[index])
		{
			continue;
		}
		if (index == g)
		{
			cout << value;
			return 0;
		}
		visited[index] = 1;
		q.push(pii(index + u, value + 1));
		q.push(pii(index - d, value + 1));
	}
	cout << "use the stairs";
	return 0;
}
