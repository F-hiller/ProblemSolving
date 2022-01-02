[10867번: 중복 빼고 정렬하기](https://www.acmicpc.net/problem/10867)

## 사고의 흐름

```cpp
int main() {
	//init
	FastIO;
	//init
	init();

	cin >> n;
	for ( i = 0; i < n; i++)
	{
		cin >> itemp1;
		s.insert(itemp1);
	}
	set<int>::iterator iter;
	for ( iter = s.begin(); iter != s.end(); iter++)
	{
		cout << *iter << " ";
	}

	return 0;
}
```
