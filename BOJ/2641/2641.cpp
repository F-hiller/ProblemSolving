int t, n, m, input1, input2;
vector<pii> resultInfo;
vector<int> base;
vector<int> reverse_base;
vector<vector<int>> inputVectors;
vector<int> vtemp;
void setting() {
	int i, j, k;
	for ( i = 0; i < n; i++)
	{
		int itemp = (base[i] + 2) % 4;
		if (!itemp)
		{
			itemp = 4;
		}
		reverse_base[n - 1 - i] = itemp;
	}
}
bool isMatched(vector<int> &a, int moveCnt) {
	int i, j, k;
	for ( i = 0; i < n; i++)
	{
		if (a[(i+moveCnt)%n] != base[i])
		{
			return 0;
		}
	}
	return 1;
}
bool isReverseMatched(vector<int> &a, int moveCnt) {
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		if (a[(i + moveCnt) % n] != reverse_base[i])
		{
			return 0;
		}
	}
	return 1;
}
void print_result(vector<int> &a) {
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void solution(int a) {
	int i, j, k;
	for ( i = 0; i < n; i++)
	{
		if (isMatched(inputVectors[a], i) || isReverseMatched(inputVectors[a], i))
		{
			resultInfo.push_back(pii(a, i));
			return;
		}
	}
}
int main() {
	//init
	FastIO;
	int i, j, k;
	cin >> n;
	reverse_base.resize(n);
	for ( i = 0; i < n; i++)
	{
		cin >> input1;
		base.push_back(input1);
	}
	cin >> t;
	for ( i = 0; i < t; i++)
	{
		for ( j = 0; j < n; j++)
		{
			cin >> input1;
			vtemp.push_back(input1);
		}
		inputVectors.push_back(vtemp);
		vtemp.clear();
	}
	setting();

	for ( i = 0; i < t; i++)
	{
		solution(i);
	}

	cout << resultInfo.size() << endl;
	for ( i = 0; i < resultInfo.size(); i++)
	{
		print_result(inputVectors[resultInfo[i].first]);
	}

	return 0;
}
