int t, n, m, input1, input2;
vector<int> v;
int main() {
	//init
	FastIO;
	int i, j, k;
	cin >> n;
	for ( i = 0; i < n; i++)
	{
		cin >> input1;
		v.push_back(input1);
	}
	sort(v.begin(), v.end());
	cin >> m;
	for ( i = 0; i < m; i++)
	{
		cin >> input1;
		cout << binary_search(v.begin(), v.end(), input1) << " ";
	}
	return 0;
}
