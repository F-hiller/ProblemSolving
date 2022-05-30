int n, m, t, itemp1, itemp2;
int last;

void solution() {
	int i, j, k;
	int last_range = last;
	for (i = 0; i < last; i++)
	{
		for (j = 0; j < last; j++)
		{
			if (i % 2 == 0 && ((i <= j && j < last - i) || (i >= j && j >= last - i))) {
				cout << "*";
				continue;
			}
			if (j % 2 == 0 && ((j <= i && i < last - j) || (j >= i && i >= last - j)))
			{
				cout << "*";
				continue;
			}
			cout << " ";
		}
		cout << endl;
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
	cin >> n;
	last = 4 * n - 3;
}
