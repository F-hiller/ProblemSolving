[2506번: 점수계산](https://www.acmicpc.net/problem/2506)

```cpp
int t, n, m, input1, input2;
int main() {
	//init
	FastIO;
	int i, j, k;
	cin >> n;
	int score = 0;
	int result = 0;
	for ( i = 0; i < n; i++)
	{
		cin >> input1;
		if (input1)
		{
			result += (++score);
		}
		else
		{
			score = 0;
		}
	}
	cout << result;
	return 0;
}
```
