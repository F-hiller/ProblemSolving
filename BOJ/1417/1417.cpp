int n, m, t, N, K, itemp1, itemp2, itemp3;
vector<int> v;
int answer;
int result = 0;

void solution() {
	int i, j, k;
	bool check;
	while (true)
	{
		check = 0;
		while (true)
		{
			check = 0;
			for (i = 0; i < n - 1; i++)
			{
				if (answer <= v[i])
				{
					check = 1;
					answer++;
					v[i]--;
					result++;
					break;
				}
			}
			if (!check)
			{
				break;
			}
			sort(v.begin(), v.end(), greater<int>());
		}
		if (!check)
		{
			break;
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
	cin >> n;
	cin >> answer;
	for (i = 1; i < n; i++)
	{
		cin >> itemp1;
		v.push_back(itemp1);
	}
	sort(v.begin(), v.end(), greater<int>());
}
