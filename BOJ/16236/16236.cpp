int t, n, m, input1, input2;
vector<vector<int>> board;
vector<vector<bool>> visited;
vector<int> vtemp;
vector<bool> visitedTemp;
pii shark;
int sharkSize = 2;
int sharkFoodCount = 0;
int resultTime = 0;

void visitedClear() {
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			visited[i][j] = 0;
		}
	}
}
void sharkEat() {
	if (++sharkFoodCount == sharkSize)
	{
		sharkFoodCount = 0;
		sharkSize++;
	}
}
pii bfs(pii ptemp) {
	queue<piii> q;
	q.push(piii(ptemp, 0));
	int count = 0;
	int nextY = n, nextX = n;
	while (!q.empty())
	{
		int checkY = nextY;
		int checkX = nextX;
		while (!q.empty() && (count == q.front().second))
		{
			piii top = q.front();
			q.pop();
			int topY = top.first.first;
			int topX = top.first.second;
			int value = top.second;
			if (((-1 < topY && topY < n) && (-1 < topX&&topX < n)) && !visited[topY][topX] && board[topY][topX] <= sharkSize)
			{
				if ((0 < board[topY][topX] && board[topY][topX] < sharkSize) && ((topY < nextY) || ((topY == nextY) && (topX <= nextX))))
				{
					nextY = topY;
					nextX = topX;
					//return pii(topY, topX);
				}
				visited[topY][topX] = 1;
				q.push(piii(pii(topY - 1, topX), value + 1));
				q.push(piii(pii(topY, topX - 1), value + 1));
				q.push(piii(pii(topY, topX + 1), value + 1));
				q.push(piii(pii(topY + 1, topX), value + 1));
			}
		}
		if (checkY != nextY || checkX != nextX)
		{
			sharkEat();
			resultTime += count;
			return pii(nextY, nextX);
		}
		count++;
	}
	return pii(-1, -1);
}
void solution() {
	while (shark != pii(-1, -1))
	{
		board[shark.first][shark.second] = 0;
		shark = bfs(shark);
		visitedClear();
	}
}
int main() {
	//init
	FastIO;
	cin >> n;
	int i, j, k;
	visitedTemp.resize(n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> input1;
			if (input1 == 9)
			{
				shark.first = i;
				shark.second = j;
				vtemp.push_back(0);
				continue;
			}
			vtemp.push_back(input1);
		}
		visited.push_back(visitedTemp);
		board.push_back(vtemp);
		vtemp.clear();
	}

	solution();
	cout << resultTime;
	return 0;
}
