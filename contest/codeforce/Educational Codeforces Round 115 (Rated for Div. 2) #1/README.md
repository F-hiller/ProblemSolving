```cpp
int t, n, m, input1, input2;
string stemp;
string arr[2];
vector<bool> visited[2];
 
bool bfs() {
	queue<pii> q;
	q.push(pii(0, 0));
	while (!q.empty())
	{
		pii top = q.front();
		q.pop();
		int topY = top.first;
		int topX = top.second;
		if (((-1 < topY&&topY < 2) && (-1 < topX&&topX < n)) && !visited[topY][topX] && arr[topY][topX] != '1')
		{
			if (topY == 1 && topX == n - 1)
			{
				cout << "YES\n";
				return 1;
			}
			visited[topY][topX] = 1;
			q.push(pii(topY + 1, topX));
			q.push(pii(topY - 1, topX));
			q.push(pii(topY, topX + 1));
			q.push(pii(topY, topX - 1));
			q.push(pii(topY + 1, topX + 1));
			q.push(pii(topY - 1, topX - 1));
			q.push(pii(topY + 1, topX - 1));
			q.push(pii(topY - 1, topX + 1));
		}
	}
	return 0;
}
int main() {
	//init
	FastIO;
	cin >> t;
	int i, j, k;
	for (i = 0; i < t; i++)
	{
		cin >> n;
		for (j = 0; j < 2; j++)
		{
			for (k = 0; k < n; k++)
			{
				visited[j].push_back(0);
			}
		}
		for (j = 0; j < 2; j++)
		{
			cin >> stemp;
			arr[j] = stemp;
		}
		if (!bfs())
		{
			cout << "NO\n";
		}
		visited[0].clear();
		visited[1].clear();
	}
	return 0;
}
```
