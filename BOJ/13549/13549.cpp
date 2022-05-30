int t, n, m, a, b, c, d, e, itemp1, itemp2;
int k;
int arr[100001];

void solution() {
	queue<pii> q;
	q.push(pii(n, 0));
	while (!q.empty())
	{
		pii front = q.front();
		int index = front.first;
		int value = front.second;
		q.pop();
		if ((-1 < index && index < 100001) && value < arr[index])
		{
			arr[index] = value;
			q.push(pii(index + 1, value + 1));
			q.push(pii(index - 1, value + 1));
			q.push(pii(2 * index, value));
		}
	}
}

int main() {
	//init
	FastIO;
	int i;
	for (i = 0; i < 100001; i++) { arr[i] = 987654321; }
	cin >> n >> k;

	solution();

	cout << arr[k];

	return 0;
}
