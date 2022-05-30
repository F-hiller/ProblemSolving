000000
111110
010000
010111
010011
011011
000*10

���������� (1, 0)�� ���� �հ� *��ġ���� ������ ���� �������� ������ �� ����. ������ ���� ���� �ʰ� *���� �������� �� *��ġ�� visited���� �̹� 1�̹Ƿ� ���� �հ� �������� ������ �� ���� �ȴ�. �̸� �ذ��ϱ� ���� ������ �ϳ� �߰��߰� (1, 0)�� ���� �հ� *��ġ�� ������ ���� visited[y][x][1]�� ���� 1�� �ȴ�. ���� ���� �ʰ� *��ġ�� �����ϸ� visited[y][x][0]�� ���� Ȯ���ϰԵǰ� ���� ���� �հ� �������� ������ �� �ְ� �ȴ�.

�迭�� �̿��� ������ �ذ��� �ȵ� ���� ������ �߰��غ��� ����� �ִٴ� ���� �˰ԵǾ���.

int n, m, t, itemp1, itemp2;
string map[1000];
bool visited[1000][1000][2];

void solution() {
	int i, j, k;
	queue<piii> q;
	q.push(piii(pii(0, 0), pii(0, 1)));
	while (!q.empty())
	{
		piii top = q.front();
		q.pop();
		int topY = top.first.first;
		int topX = top.first.second;
		int isBreak = top.second.first;
		int value = top.second.second;
		if (topY == n-3 && topX == m-1)
		{
			cout << "";
		}
		if (topY == n - 1 && topX == m - 1)
		{
			cout << value;
			return;
		}
		if (-1 < topY&&topY < n &&-1 < topX&&topX < m && !visited[topY][topX][isBreak])
		{
			visited[topY][topX][isBreak] = 1;
			if (map[topY][topX] == '1' )
			{
				if (isBreak)
				{
					continue;
				}
				q.push((piii(pii(topY + 1, topX), pii(1, value + 1))));
				q.push((piii(pii(topY, topX - 1), pii(1, value + 1))));
				q.push((piii(pii(topY, topX + 1), pii(1, value + 1))));
				q.push((piii(pii(topY - 1, topX), pii(1, value + 1))));
				continue;
			}
			q.push((piii(pii(topY + 1, topX), pii(isBreak, value + 1))));
			q.push((piii(pii(topY, topX - 1), pii(isBreak, value + 1))));
			q.push((piii(pii(topY, topX + 1), pii(isBreak, value + 1))));
			q.push((piii(pii(topY - 1, topX), pii(isBreak, value + 1))));
		}
	}
	cout << -1;
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
	for (i = 0; i < n; i++)
	{
		cin >> map[i];
	}
}
