int n, m, t, N, K, itemp1, itemp2;
int visited[SHARING];
int result = 0;
int cnt = 0;

void solution() {
	int i, j, k;
	bool first_check = 0;
	queue<pii> q;
	q.push(pii(N, 1));
	while (!q.empty())
	{
		pii top = q.front();
		q.pop();
		int index = top.first;
		int value = top.second;
		if (index == K)
		{
			if (!first_check)
			{
				first_check = 1;
				result = value;
				cnt++;
				continue;
			}
			if (result > value)
			{
				cnt = 1;
				result = value;
				continue;
			}
			if (result == value)
			{
				cnt++;
			}
			continue;
		}
		if (first_check)
		{
			continue;
		}
		if (-1 < index && index < SHARING && (visited[index] == 0 || visited[index] >= value))
		{
			visited[index] = value;
			q.push(pii(index + 1, value + 1));
			q.push(pii(index - 1, value + 1));
			q.push(pii(index * 2, value + 1));
		}
	}
}

int main() {
	//init
	FastIO;
	//init
	int i, j, k;
	init();

	solution();

	cout << result - 1 << endl << cnt;

	return 0;
}

void init() {
	int i, j, k;
	cin >> N >> K;
}
