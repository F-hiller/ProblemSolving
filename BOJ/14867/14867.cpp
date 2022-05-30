int a, b, c, d;
map<pii, bool> visited;

void bfs() {
	int i, j;
	queue<piii> q;
	q.push(piii(pii(0, 0), 0));
	visited[pii(0, 0)] = 0;
	while (!q.empty())
	{
		piii front = q.front();
		q.pop();
		int a_cur = front.first.first;
		int b_cur = front.first.second;
		int value = front.second;
		if (a_cur == c && b_cur == d)
		{
			cout << value;
			return;
		}
		if (!visited[pii(a_cur, b_cur)])
		{
			visited[pii(a_cur, b_cur)] = 1;
			q.push(piii(pii(0, b_cur), value + 1));
			q.push(piii(pii(a_cur, 0), value + 1));
			q.push(piii(pii(a, b_cur), value + 1));
			q.push(piii(pii(a_cur, b), value + 1));
			if (a_cur + b_cur >= b)
			{
				q.push(piii(pii(a_cur - (b - b_cur), b), value + 1));
			}
			else
			{
				q.push(piii(pii(0, a_cur + b_cur), value + 1));
			}
			if (a_cur + b_cur >= a)
			{
				q.push(piii(pii(a, b_cur - (a - a_cur)), value + 1));
			}
			else
			{
				q.push(piii(pii(a_cur + b_cur, 0), value + 1));
			}
		}
	}
	cout << -1;
}

int main() {
	//init
	FastIO;
	int i, j, k;

	//solution
	cin >> a >> b >> c >> d;

	bfs();

	return 0;
}
