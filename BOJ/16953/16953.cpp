int t, n, m, input1, input2;
ll a, b;

void solution(ll value, ll result) {
	if (value > 1000000000)
	{
		return;
	}
	if (value == b)
	{
		cout << result + 1;
		exit(0);
	}
	solution(2 * value, result + 1);
	solution(10 * value + 1, result + 1);
}

int main() {
	//init
	FastIO;
	int i, j, k;
	cin >> a >> b;
	solution(a, 0);
	cout << -1;
	return 0;
}
