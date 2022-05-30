int t, n, m, input1, input2;
ll input;
vector<vector<long long>> arr = { {1, 1}, {1, 0} };
vector<vector<long long>> base = { {1, 0}, {0, 1} };
void comple(vector<vector<long long>>& a) {
	vector<vector<long long>> c(2, vector<long long>(2));
	c[0][0] = ((a[0][0] * arr[0][0]) % MAX_VALUE + (a[0][1] * arr[1][0]) % MAX_VALUE) % MAX_VALUE;
	c[0][1] = ((a[0][0] * arr[0][1]) % MAX_VALUE + (a[0][1] * arr[1][1]) % MAX_VALUE) % MAX_VALUE;
	c[1][0] = ((a[1][0] * arr[0][0]) % MAX_VALUE + (a[1][1] * arr[1][0]) % MAX_VALUE) % MAX_VALUE;
	c[1][1] = ((a[1][0] * arr[0][1]) % MAX_VALUE + (a[1][1] * arr[1][1]) % MAX_VALUE) % MAX_VALUE;
	a = c;
}
int main() {
	//init
	FastIO;
	cin >> input;
	while (input)
	{
		if (input % 2){comple(base);}
		comple(arr);
		input /= 2;
	}
	cout << base[0][1] << '\n';
	return 0;
}
