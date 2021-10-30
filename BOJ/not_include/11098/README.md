[boj - 11098](https://www.acmicpc.net/problem/11098)
```int main() {
	//init
	FastIO;
	int i, j, k;
	cin >> t;
	for ( i = 0; i < t; i++)
	{
		cin >> n;
		int result = 0;
		string name;
		for ( j = 0; j < n; j++)
		{
			cin >> input1 >> stemp;
			if (input1 > result)
			{
				result = input1;
				name = stemp;
			}
		}
		cout << name << endl;
	}
	return 0;
}
```
