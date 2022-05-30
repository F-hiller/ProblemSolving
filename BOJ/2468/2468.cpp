int n, m, itemp1, itemp2, itemp3;
int arr[100][100];
bool visited[100][100];
int h = 0;
int result = 1, result_temp;

void solution(int y, int x) {
	int i, j, k;
	bool check = 0;
	queue<pii> q;
	q.push(pii(y, x));
	while (!q.empty())
	{
		pii top = q.front();
		q.pop();
		int topY = top.first;
		int topX = top.second;
		if (-1 < topY && topY < n && -1 < topX && topX<n && !visited[topY][topX] && arr[topY][topX] > h)
		{
			check = 1;
			visited[topY][topX] = 1;
			q.push(pii(topY + 1, topX));
			q.push(pii(topY, topX - 1));
			q.push(pii(topY - 1, topX));
			q.push(pii(topY, topX + 1));
		}
	}
	if (check)
	{
		result_temp++;
	}
}

void clear() {
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			visited[i][j] = 0;
		}
	}
}

int main() {
	//init
	FastIO;
	int i, j, k;

	//input
	init();

	for (h = 0; h < 101; h++)
	{
		result_temp = 0;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (!visited[i][j])
				{
					solution(i, j);
				}
			}
		}
		if (result < result_temp)
		{
			result = result_temp;
		}
		clear();
	}

	cout << result;

	return 0;
}
void init() {
	int i, j, k;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
}
