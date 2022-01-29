[11721번: 열 개씩 끊어 출력하기](https://www.acmicpc.net/problem/11721)

```jsx
void init() {
	int i, j, k;
	string s;
	cin >> s;
	for ( i = 0; i < s.size(); i++)
	{
		cout << s[i];
		if ((i+1) % 10 == 0)
		{
			cout << endl;
		}
	}
}
```
