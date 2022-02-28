[4458번: 첫 글자를 대문자로](https://www.acmicpc.net/problem/4458)

//ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 

위 코드를 주석처리해야한다.

```cpp
//main function
int main() {
	//ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//init
	int i, j, k, itemp;
	//solution
	string s;
	cin >> n;
	getchar();
	for (int i = 0; i < n; i++)
	{
		getline(cin, s);
		if (s[0] >= 97)
			s[0] -= 32;

		cout << s << endl;
	}
	return 0;
}
```
