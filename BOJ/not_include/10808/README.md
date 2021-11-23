[10808번: 알파벳 개수](https://www.acmicpc.net/problem/10808)

```cpp
int t, n, m, input1, input2;
string stemp;
int arr[101];
int main() {
	//init
	FastIO;
	int i, j, k;
	cin >> stemp;
	for ( i = 0; i < stemp.size(); i++)
	{
		arr[stemp[i] - 'a']++;
	}
	for (i = 0; i < 26; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}
```
