int t, n, m, input1, input2;
ll sum = 0;
int arr[10000];

void solution() {
	int i, j, k;
	int pre, cur;
	cur = arr[n - 1];
	for ( i = n - 2; i > -1; i--)
	{
		pre = cur;
		cur = arr[i];
		if (cur < pre)
		{
			for ( j = 0; j < i; j++)
			{
				cout << arr[j] << " ";
			}
			vector<int> v;
			for ( j = i + 1; j < n; j++)
			{
				v.push_back(arr[j]);
			}
			sort(v.begin(), v.end());
			for ( j = 0; j < v.size(); j++)
			{
				if (v[j] > cur)
				{
					cout << v[j] << " ";
					v[j] = cur;
					break;
				}
			}
			for (j = 0; j < v.size(); j++)
			{
				cout << v[j] << " ";
			}
			return;
		}
	}
	cout << -1;
}

int main() {
	//init
	FastIO;
	int i, j, k;
	cin >> n;
	for ( i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	solution();

	return 0;
}
