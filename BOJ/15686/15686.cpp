typedef pair<pii, int> piii;
int t, n, m, a, b, c, d, e, itemp1, itemp2;
int result = 987654321;
vector<int> vtemp;
vector<vector<int>> arr;

vector<bool> visitedTemp;
vector<vector<bool>> visited;

vector<pii> chicken;
vector<bool> chickenCheck;

void bfs() {
	queue<piii> q;
	int resultValue = 0;
	int i, j, k;
	for (i = 0; i < chicken.size(); i++)
	{
		if (chickenCheck[i])
		{
			q.push(piii(chicken[i], 0));
		}
	}
	while (!q.empty())
	{
		piii top = q.front();
		q.pop();
		int topY = top.first.first;
		int topX = top.first.second;
		int topValue = top.second;
		if (((-1 < topY&&topY < n) && (-1 < topX&&topX < n)) && !visited[topY][topX])
		{
			visited[topY][topX] = 1;
			q.push(piii(pii(topY + 1, topX), topValue + 1));
			q.push(piii(pii(topY - 1, topX), topValue + 1));
			q.push(piii(pii(topY, topX + 1), topValue + 1));
			q.push(piii(pii(topY, topX - 1), topValue + 1));
			if (arr[topY][topX] == 1)
			{
				resultValue += topValue;
				if (resultValue > result)
				{
					while (!q.empty()){q.pop();}
					for (i = 0; i < n; i++) { for (j = 0; j < n; j++) { visited[i][j] = 0; } }
					return;
				}
			}
		}
	}
	if (result > resultValue)
	{
		result = resultValue;
	}
	for (i = 0; i < n; i++) { 
		for (j = 0; j < n; j++) { 
			visited[i][j] = 0; 
		} 
	}
}
void solution(int depth, int select, int num) {
	if (select == num)
	{
		bfs();
		return;
	}
	if (depth == chicken.size())
	{
		return;
	}
	chickenCheck[depth] = 1;
	solution(depth + 1, select + 1, num);
	chickenCheck[depth] = 0;
	solution(depth + 1, select, num);
}
int main() {
	//init
	FastIO;
	cin >> n >> m;
	int i, j, k;
	vtemp.resize(n);
	visitedTemp.resize(n);
	for (i = 0; i < n; i++)
	{
		arr.push_back(vtemp);
		visited.push_back(visitedTemp);
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j]==2)
			{
				chicken.push_back(pii(i, j));
				chickenCheck.push_back(0);
			}
		}
	}

	for (i = 1; i <= m; i++)
	{
		solution(0, 0, i);
	}

	cout << result;

	return 0;
}
