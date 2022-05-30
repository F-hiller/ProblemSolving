
#define SHARING 1001

int n, m, t, N, K;

//additional variables
int visited[SHARING];
string s[SHARING];

void bfs(int start, int finish) {
	int i, j;
	queue<pii> q;

	q.push(pii(start, start));

	while (!q.empty())
	{
		pii top = q.front();
		q.pop();
		int index = top.first;
		int pre = top.second;

		if (index == finish)
		{
			stack<int> path;
			path.push(index);
			while (pre != index)
			{
				index = pre;
				pre = visited[pre];
				path.push(index);
			}
			while (!path.empty())
			{
				cout << path.top() << " ";
				path.pop();
			}
			return ;
		}
		if (0 < index&&index <= n && !visited[index])
		{
			visited[index] = pre;
			int cnt;
			for (i = 1; i <= n; i++)
			{
				cnt = 0;
				for (j = 0; j < K; j++)
				{
					if (s[index][j] != s[i][j])
					{
						cnt++;
						if (cnt >= 2)
						{
							break;
						}
					}
				}
				if (cnt == 1)
				{
					q.push(pii(i, index));
				}
			}
		}
	}
	cout << -1;
}

//main function
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//init
	int t, i, j, k, itemp;
	int start, finish;

	//solution
	cin >> n >> K;
	for (i = 1; i <= n; i++)
	{
		cin >> s[i];
	}
	cin >> start >> finish;

	bfs(start, finish);

	return 0;
}
