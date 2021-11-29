[2576번: 홀수](https://www.acmicpc.net/problem/2576)

```cpp
int t, n, m, input1, input2;
int main() {
	//init
	FastIO;
	int i, j, k;
	int sum = 0;
	int minOdd = 987654321;
	for ( i = 0; i < 7; i++)
	{
		cin >> input1;
		if (input1%2)
		{
			sum += input1;
			if (minOdd > input1)
			{
				minOdd = input1;
			}
		}
	}
	if (sum == 0)
	{
		cout << -1;
		return 0;
	}
	cout << sum << endl << minOdd;
	return 0;
}
```
