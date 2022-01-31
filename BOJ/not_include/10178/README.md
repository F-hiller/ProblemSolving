[https://www.acmicpc.net/problem/10178](https://www.acmicpc.net/problem/10178)

```jsx
void init() {
	int i, j, k;
	cin >> t;
	for ( i = 0; i < t; i++)
	{
		cin >> n >> m;
		cout << "You get " << n / m << " piece(s) and your dad gets " << n % m << " piece(s).\n";
	}
}
```
