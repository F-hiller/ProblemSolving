[9086번: 문자열](https://www.acmicpc.net/problem/9086)

```cpp
int t, n, m, input1, input2;
string stemp;
int main() {
	//init
	FastIO;
	int i, j, k;
	cin >> n;
	for ( i = 0; i < n; i++)
	{
		cin >> stemp;
		cout << stemp[0] << stemp[stemp.size() - 1] << endl;
	}

	return 0;
}
```
