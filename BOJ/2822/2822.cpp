int n, m, t, itemp1, itemp2;
vector<int> v;
int result = 0;

struct pred {
	bool operator()(pii a, pii b) {
		return a.first < b.first;
	}
};
priority_queue<pii, vector<pii>, pred> pq;

void solution() {
	int i, j, k;
	for ( i = 0; i < 5; i++)
	{
		pii top = pq.top();
		pq.pop();
		result += top.first;
		v.push_back(top.second);
	}
	sort(v.begin(), v.end());
	cout << result << endl;
	for ( i = 0; i < 5; i++)
	{
		cout << v[i] << " ";
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
	for ( i = 0; i < 8; i++)
	{
		cin >> itemp1;
		pq.push(pii(itemp1, i + 1));
	}
}
