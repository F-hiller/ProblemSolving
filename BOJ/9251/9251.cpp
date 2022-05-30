int n, m, t, N, K, itemp1, itemp2, itemp3;
string s1, s2;
int arr[1001][1001];

void solution() {
	int i, j, k;
	for ( i = 1; i <= s2.size(); i++)
	{
		for ( j = 1; j <= s1.size(); j++)
		{
			if (s2[i-1] != s1[j-1])
			{
				arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
				continue;
			}
			arr[i][j] = arr[i - 1][j - 1] + 1;
		}
	}
	cout << arr[s2.size()][s1.size()];
	if (DEBUG)
	{
		cout << endl;
		for (i = 1; i <= s2.size(); i++)
		{
			for (j = 1; j <= s1.size(); j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
	}
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
	cin >> s1 >> s2;
}
