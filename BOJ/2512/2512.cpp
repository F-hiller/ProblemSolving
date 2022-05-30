int i, j, k, n, m, t, itemp1, itemp2;
int budget, limit, result;
int max_value = 0;
vector<int> v;
void solution() {
	int i, j, k;
	int left = 1, right = max_value, middle;
	int sum;
	while (left<=right)
	{
		middle = (left + right) / 2;
		sum = 0;

		for ( i = 0; i < n; i++)
		{
			if (v[i] > middle)
			{
				sum += middle;
			}
			else
			{
				sum += v[i];
			}
			if (sum > budget)
			{
				break;
			}
		}

		if (sum > budget)
		{
			right = middle - 1;
		}
		if (sum <= budget)
		{
			result = middle;
			left = middle + 1;
		}
	}
	cout << result;
}

int main() {
	//init
	FastIO;
	//init
	init();

	solution();

	return 0;
}

void init() {
	int i, j, k;
	cin >> n;
	for ( i = 0; i < n; i++)
	{
		cin >> itemp1;
		if (itemp1 > max_value)
		{
			max_value = itemp1;
		}
		v.push_back(itemp1);
	}
	cin >> budget;
}
