ll n, m, itemp1, itemp2, itemp3;
char arr[10];
ll ans[10];
bool visited[10];
ll max_value = 0, min_value = 9996543219;

void solution(int depth) {
	int i, j, k;
	if (depth == n+1)
	{
		ll sum = ans[0];
		for (i = 1; i <= n; i++)
		{
			sum *= 10;
			sum += ans[i];
		}
		if (max_value < sum)
		{
			max_value = sum;
		}
		if (min_value > sum)
		{
			min_value = sum;
		}
		return;
	}
	if (depth == 0)
	{
		for (i = 0; i < 10; i++)
		{
			visited[i] = 1;
			ans[depth] = i;
			solution(depth + 1);
			visited[i] = 0;
		}
		return;
	}
	ll pre = ans[depth - 1];
	bool check;
	if (arr[depth - 1] == '<')
	{
		check = 1;
	}
	else
	{
		check = 0;
	}
	for (i = 0; i < 10; i++)
	{
		if (visited[i])
		{
			continue;
		}
		if ((check && pre < i) || (!check && pre > i))
		{
			visited[i] = 1;
			ans[depth] = i;
			solution(depth + 1);
			visited[i] = 0;
			continue;
		}
		//pre == i는 존재할 수 없다.
	}

}

int main() {
	//init
	FastIO;
	int i, j, k;

	//input
	init();

	solution(0);
	cout << max_value << endl;
	if (min_value < (ll)pow(10, n))
	{
		cout << 0;
	} 
	cout << min_value;

	return 0;
}
void init() {
	int i, j, k;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}
