[5218번: 알파벳 거리](https://www.acmicpc.net/problem/5218)

```cpp
int t, n, m, input1, input2;
string str1, str2;
int solution(char c1, char c2) {
	if (c1 > c2)
	{
		return (c2 + 26) - c1;
	}
	else
	{
		return c2 - c1;
	}
}
int main() {
	//init
	FastIO;
	int i, j, k;
	cin >> t;
	for ( i = 0; i < t; i++)
	{
		cin >> str1 >> str2;
		cout << "Distances: ";
		for ( j = 0; j < str1.size(); j++)
		{
			cout << solution(str1[j], str2[j]) << " ";
		}
		cout << endl;
	}

	return 0;
}
```
