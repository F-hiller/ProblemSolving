[10797번: 10부제](https://www.acmicpc.net/problem/10797)

```cpp
int t, n, m, input1, input2;
int main() {
	//init
	FastIO;
	int i, j, k;
	cin >> n;
	int result = 0;
	for ( i = 0; i < 5; i++)
	{
		cin >> input1;
		if (input1 == n)
		{
			result++;
		}
	}
	cout << result;

	return 0;
}
```
