int n, m, t, N, K, itemp1, itemp2, itemp3;
bool isDangerous[1001][1001];
bool chessMap[1001][1001];
vector<pii> queens, knights, pawns;
int queenDirY[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int queenDirX[] = {0, 1, 1, 1, 0, -1, -1, -1};
int knightDirY[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int knightDirX[] = {1, 2, 2, 1, -1, -2, -2, -1};
int result = 0;

void solution() {
	int i, j, k;
	queue<piii> q;
	for ( i = 0; i < queens.size(); i++)
	{
		pii queen = queens[i];
		for ( j = 0; j < 8; j++)
		{
			q.push(piii(pii(queen.first + queenDirY[j], queen.second + queenDirX[j]), j));
		}
		while (!q.empty())
		{
			piii top = q.front();
			q.pop();
			int topY = top.first.first;
			int topX = top.first.second;
			int dir = top.second;
			if (-1<topY&&topY<n&&-1<topX&&topX<m&&!chessMap[topY][topX])
			{
				isDangerous[topY][topX] = 1;
				q.push(piii(pii(topY + queenDirY[dir], topX + queenDirX[dir]), dir));
			}
		}
	}
	for ( i = 0; i < knights.size(); i++)
	{
		pii knight = knights[i];
		int knightY, knightX;
		for ( j = 0; j < 8; j++)
		{
			knightY = knight.first + knightDirY[j];
			knightX = knight.second + knightDirX[j];
			if (-1 < knightY && knightY < n && -1 < knightX && knightX < m)
			{
				isDangerous[knightY][knightX] = 1;
			}
		}
	}
	for ( i = 0; i < n; i++)
	{
		for ( j = 0; j < m; j++)
		{
			if (!isDangerous[i][j] && !chessMap[i][j])
			{
				result++;
			}
		}
	}

	cout << result;
}

int main() {
	//init
	FastIO;
	//init
	int i, j, k;
	init();

	solution();

	return 0;
}

void init() {
	int i, j, k;
	cin >> n >> m;
	cin >> itemp1;
	for ( i = 0; i < itemp1; i++)
	{
		cin >> itemp2 >> itemp3;
		itemp2--;
		itemp3--;
		queens.push_back(pii(itemp2, itemp3));
		isDangerous[itemp2][itemp3] = 1;
		chessMap[itemp2][itemp3] = 1;
	}
	cin >> itemp1;
	for (i = 0; i < itemp1; i++)
	{
		cin >> itemp2 >> itemp3;
		itemp2--;
		itemp3--;
		knights.push_back(pii(itemp2, itemp3));
		isDangerous[itemp2][itemp3] = 1;
		chessMap[itemp2][itemp3] = 1;
	}
	cin >> itemp1;
	for (i = 0; i < itemp1; i++)
	{
		cin >> itemp2 >> itemp3;
		itemp2--;
		itemp3--;
		pawns.push_back(pii(itemp2, itemp3));
		isDangerous[itemp2][itemp3] = 1;
		chessMap[itemp2][itemp3] = 1;
	}
}
