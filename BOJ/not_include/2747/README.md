[2747번: 피보나치 수](https://www.acmicpc.net/problem/2747)

```cpp
int t, n, m, input1, input2;

int main() {
	//init
	FastIO;
	int i, j, k;
	cin >> n;
	int pre = 0;
	int cur = 1;
	int itemp;
	for ( i = 1; i < n; i++)
	{
		itemp = pre;
		pre = cur;
		cur += itemp;
	}
	cout << cur;

	return 0;
}
```
