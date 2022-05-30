int i, j, k, n, m, t, itemp1, itemp2;
int K, itemp3, itemp4;
bool visited[100][100];
pii p1[100], p2[100];
vector<int> result;
void solution(int y, int x) {
	int i, j, k;
	int area = 0;

	queue<pii> q;
	q.push(pii(y, x));

	while (!q.empty())
	{
		pii top = q.front();
		q.pop();
		int topY = top.first;
		int topX = top.second;
		if (-1 < topY&&topY < n&&-1 < topX&&topX < m && !visited[topY][topX])
		{
			visited[topY][topX] = 1;
			area++;
			q.push(pii(topY + 1, topX));
			q.push(pii(topY, topX + 1));
			q.push(pii(topY, topX - 1));
			q.push(pii(topY - 1, topX));
		}
	}
	result.push_back(area);
}

int main() {
	//init
	FastIO;
	//init
	init();

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (!visited[i][j])
			{
				solution(i, j);
			}
		}
	}

	sort(result.begin(), result.end());

	cout << result.size() << endl;
	for (i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}

	return 0;
}

void init() {
	int i, j, k;
	cin >> n >> m >> K;
	for (i = 0; i < K; i++)
	{
		cin >> itemp1 >> itemp2 >> itemp3 >> itemp4;
		itemp3--;
		itemp4--;
		for (j = itemp1; j <= itemp3; j++)
		{
			for (k = itemp2; k <= itemp4; k++)
			{
				visited[k][j] = 1;
			}
		}
	}
}
