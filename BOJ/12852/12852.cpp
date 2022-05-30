int t, n, m, a, b, c, d, e, itemp1, itemp2;
int arr[MAX_VALUE];
stack<int> s;

void solution() {
	queue<piii> q;
	q.push(piii(pii(n, 0), n));
	while (!q.empty())
	{
		piii top = q.front();
		q.pop();
		int index = top.first.first;
		int value = top.first.second;
		int preIndex = top.second;
		if (index == 1)
		{
			cout << value << endl;
			arr[index] = preIndex;
			int cur = index, pre=arr[index];
			while (cur!=pre)
			{
				s.push(cur);
				cur = pre;
				pre = arr[cur];
			}
			s.push(cur);
			while (!s.empty())
			{
				cout << s.top() << " ";
				s.pop();
			}
			break;
		}
		if (arr[index] == 987654321)
		{
			arr[index] = preIndex;
			if (!(index%3))
			{
				q.push(piii(pii(index / 3, value + 1), index));
			}
			if (!(index % 2))
			{
				q.push(piii(pii(index / 2, value + 1), index));
			}
			q.push(piii(pii(index - 1, value + 1), index));
		}
	}
}

int main() {
	//init
	FastIO;
	cin >> n;
	int i, j, k;
	for ( i = 1; i <= n; i++)
	{
		arr[i] = 987654321;
	}
	solution();

	return 0;
}
