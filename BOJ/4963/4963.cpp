int t, n, m, input1, input2;
int itemp;
int cnt = 1;
vector<int> vtemp;
vector<vector<int>> v;
vector<bool> visitedTemp;
vector<vector<bool>> visited;
void bfs(int y, int x) {
	queue<pii> q;
	q.push(pii(y, x));
	while (!q.empty())
	{
		pii top = q.front();
		q.pop();
		int topY = top.first;
		int topX = top.second;
		if (((-1 < topY&&topY < input2) && (-1 < topX&&topX < input1)) && !visited[topY][topX] && v[topY][topX] == 1)
		{
			visited[topY][topX] = 1;
			q.push(pii(topY - 1, topX));
			q.push(pii(topY - 1, topX + 1));
			q.push(pii(topY, topX + 1));
			q.push(pii(topY + 1, topX + 1));
			q.push(pii(topY + 1, topX));
			q.push(pii(topY + 1, topX - 1));
			q.push(pii(topY, topX - 1));
			q.push(pii(topY - 1, topX - 1));
		}
	}
	cnt++;
}
void solution() {
	int i, j, k;
	for (i = 0; i < input2; i++)
	{
		for (j = 0; j < input1; j++)
		{
			if (v[i][j] == 1 && !visited[i][j])
			{
				bfs(i, j);
			}
		}
	}
}
int main() {
	//init
	FastIO;
	int i, j, k;
	cin >> input1 >> input2;
	while (!(input1 == 0 && input2 == 0))
	{
		for (i = 0; i < input2; i++)
		{
			for (j = 0; j < input1; j++)
			{
				cin >> itemp;
				vtemp.push_back(itemp);
				visitedTemp.push_back(0);
			}
			visited.push_back(visitedTemp);
			v.push_back(vtemp);
			visitedTemp.clear();
			vtemp.clear();
		}

		solution();

		cout << cnt - 1 << endl;
		cnt = 1;

		v.clear();
		visited.clear();
		cin >> input1 >> input2;
	}
	return 0;
}
