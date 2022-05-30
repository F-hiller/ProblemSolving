int n, m, itemp1, itemp2, itemp3;
int arr[100][100];
ll cnt_arr[100][100];

void solve() {
	int i, j, k, l;
	cnt_arr[0][0] = 1;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == n-1 && j == n-1)
			{
				break;
			}
			if (j + arr[i][j] < n)
			{
				cnt_arr[i][j + arr[i][j]] += cnt_arr[i][j];
			}
			if (i + arr[i][j] < n)
			{
				cnt_arr[i + arr[i][j]][j] += cnt_arr[i][j];
			}
		}
	}
	cout << cnt_arr[n - 1][n - 1];
}

int main() {
	//init
	FastIO;
	int i, j, k;

	//input
	init();

	//solve problem
	solve();

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
