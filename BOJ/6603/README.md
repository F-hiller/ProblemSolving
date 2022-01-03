[6603번: 로또](https://www.acmicpc.net/problem/6603)

## 사고의 흐름

백트래킹으로 6개씩 골라내는 방식을 사용하였다.

```cpp
int n, m, itemp1, itemp2, itemp3;
int arr[13];
int ans[13];

void solve(int depth) {
	int i, j, k;
	if (depth == 6)
	{
		for ( i = 0; i < 6; i++)
		{
			cout << ans[i] << " ";
		}
		cout << endl;
		return;
	}
	if (depth == 0)
	{
		for (i = 0; i < n; i++)
		{
			ans[depth] = arr[i];
			solve(depth + 1);
		}
		return;
	}
	for ( i = 0; i < n; i++)
	{
		if (arr[i] > ans[depth-1])
		{
			ans[depth] = arr[i];
			solve(depth + 1);
		}
	}

}

int main() {
	//init
	FastIO;
	int i, j, k;

	//input
	init();
	cin >> n;
	while (n)
	{
		for (i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		//solve problem
		solve(0);
		cout << endl;

		cin >> n;
	}

	return 0;
}
```
