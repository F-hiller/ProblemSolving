[10953번 - A+B - 6](https://www.acmicpc.net/problem/10953)

```jsx
void init() {
	int i, j, k;
	string s;
	cin >> n; 
	for ( i = 0; i < n; i++)
	{
		cin >> s;
		cout << (s[0] - '0') + (s[2] - '0') << endl;
	}
}
```
