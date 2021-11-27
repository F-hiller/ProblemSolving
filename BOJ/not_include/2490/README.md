[2490번: 윷놀이](https://www.acmicpc.net/problem/2490)

```cpp
int t, n, m, input1, input2;
int arr[3][4];
int main() {
	//init
	FastIO;
	int i, j, k;
	for ( i = 0; i < 3; i++)
	{
		int cnt = 0;
		for ( j = 0; j < 4; j++)
		{
			cin >> input1;
			if (input1)
			{
				cnt++;
			}
		}
		if (cnt == 1)
		{
			cout << "C" << endl;
		}
		if (cnt == 2)
		{
			cout << "B" << endl;
		}
		if (cnt == 3)
		{
			cout << "A" << endl;
		}
		if (cnt == 4)
		{
			cout << "E" << endl;
		}
		if (cnt == 0)
		{
			cout << "D" << endl;
		}
	}

	return 0;
}
```
