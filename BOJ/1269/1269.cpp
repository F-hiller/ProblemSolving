int n, m, t, N, K, itemp1, itemp2, itemp3;
vector<int> v1, v2, result1, result2;
int result = 0;

void solution() {
	int i, j, k;
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	result1.resize(v1.size() + v2.size());
	result2.resize(result1.size());
	auto iter1 = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), result1.begin());
	auto iter2 = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), result2.begin());
	for ( i = 0; i < result1.size(); i++)
	{
		if (result1[i] == 0)
		{
			result += i;
			break;
		}
	}
	for (i = 0; i < result2.size(); i++)
	{
		if (result2[i] == 0)
		{
			result += i;
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
	cin >> n >> m;
	for ( i = 0; i < n; i++)
	{
		cin >> itemp1;
		v1.push_back(itemp1);
	}
	for ( i = 0; i < m; i++)
	{
		cin >> itemp1;
		v2.push_back(itemp1);
	}
}
