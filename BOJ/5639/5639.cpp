int n, m, itemp1, itemp2, itemp3;
vector<int> v;

void solution(int first, int last) {
	//cout << "first and last : " << first << " " << last << endl;
	int i, j, k;
	if (first >= last)
	{
		if (first == last)
		{
			cout << v[first] << endl;
		}
		return;
	}
	for (i = first + 1; i <= last; i++)
	{
		if (v[i] > v[first])
		{
			solution(first + 1, i - 1);
			solution(i, last);
			cout << v[first] << endl;
			return;
		}
	}
	solution(first + 1, last);
	cout << v[first] << endl;
}

int main() {
	//init
	FastIO;
	int i, j, k;

	//input
	init();

	solution(1, v.size() - 1);

	return 0;
}
void init() {
	int i, j, k;
	v.push_back(-1);
	if (DEBUG)
	{
		cin >> n;
		while (n)
		{
			v.push_back(n);
			cin >> n;
		}
		return;
	}
	while (cin >> n) {
		v.push_back(n);
	}
}
