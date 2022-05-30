int t, n, m, input1, input2;
int N, K;
void solution() {
	int fir = 1;
	int last = K;
	int num = N - K * (K + 1) / 2;
	while (num >= K)
	{
		fir++;
		last++;
		num -= K;
	}
	if ( num == 0)
	{
		cout << K - 1;
		return;
	}
	cout << K;
}
int main() {
	//init
	FastIO;
	int i, j, k;
	cin >> N >> K;
	if (N < K*(K + 1) / 2)
	{
		cout << -1;
		return 0;
	}

	solution();

	return 0;
}
