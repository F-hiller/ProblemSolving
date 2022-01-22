[2010번: 플러그](https://www.acmicpc.net/problem/2010)

```jsx
void init() {
	int i, j, k;
	cin >> n;
	for ( i = 0; i < n; i++)
	{
		cin >> itemp1;
		result += itemp1 - 1;
	}
	cout << result;
}
```
