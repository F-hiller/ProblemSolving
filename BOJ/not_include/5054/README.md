[5054번: 주차의 신](https://www.acmicpc.net/problem/5054)

```cpp
void init() {
	int i, j, k;
	cin >> t;
	for ( i = 0; i < t; i++)
	{
		cin >> n;
		for ( j = 0; j < n; j++)
		{
			cin >> itemp1;
			v.push_back(itemp1);
		}
		sort(v.begin(), v.end());
		cout << (v[n - 1]- v[0]) * 2 << endl;
		v.clear();
	}
}
```
