[9085번: 더하기](https://www.acmicpc.net/problem/9085)

```cpp
int t, n, m, input1, input2;
int main() {
	//init
	FastIO;
	int i, j, k;
	cin >> t;
	for ( i = 0; i < t; i++)
	{
		cin >> n;
		int sum = 0;
		for ( j = 0; j < n; j++)
		{
			cin >> input1;
			sum += input1;
		}
		cout << sum << endl;
	}

	return 0;
}
```
