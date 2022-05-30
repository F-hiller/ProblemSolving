int n, m, t, N, K, itemp1, itemp2;
set<int> s;
int arr[8];
int ans[8];
int cnt;

void solution(int depth) {
	int i, j, k;
	if (depth == m)
	{
		for ( i = 0; i < m; i++)
		{
			cout << ans[i] << " ";
		}
		cout << endl;
		return;
	}
	if (depth == 0)
	{
		for (i = 0; i < cnt; i++)
		{
			ans[depth] = arr[i];
			solution(depth + 1);
		}
		return;
	}
	for ( i = 0; i < cnt; i++)
	{
		if (ans[depth-1] > arr[i])
		{
			continue;
		}
		ans[depth] = arr[i];
		solution(depth + 1);
	}
}

int main() {
	//init
	FastIO;
	//init
	int i, j, k;
	init();

	solution(0);

	return 0;
}

void init() {
	int i, j, k;
	cin >> n >> m;
	for ( i = 0; i < n; i++)
	{
		cin >> itemp1;
		s.insert(itemp1);
	}
	i = 0;
	for (auto iter = s.begin(); iter != s.end(); iter++)
	{
		arr[i++] = *iter;
	}
	cnt = s.size();
}
