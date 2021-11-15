[11655번: ROT13](https://www.acmicpc.net/problem/11655)

```cpp
int t, n, m, input1, input2;
string stemp;
char ctemp;
char encryption(char c) {
	if ('a' <= ctemp && ctemp <= 'z')
	{
		c -= 'a';
		c += 13;
		c %= 26;
		c += 'a';
	}
	if ('A' <= ctemp && ctemp <= 'Z')
	{
		c -= 'A';
		c += 13;
		c %= 26;
		c += 'A';
	}
	return (char)c;
}
int main() {
	//init
	FastIO;
	int i, j, k;
	getline(cin, stemp);
	for ( i = 0; i < stemp.size(); i++)
	{
		ctemp = stemp[i];
		if (('a' <= ctemp && ctemp <= 'z') || ('A' <= ctemp && ctemp <= 'Z'))
		{
			stemp[i] = encryption(ctemp);
		}
	}
	cout << stemp;
	return 0;
}
```
