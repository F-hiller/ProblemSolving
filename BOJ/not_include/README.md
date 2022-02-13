[3058번: 짝수를 찾아라](https://www.acmicpc.net/problem/3058)

```cpp
	cin >> t;
	for ( i = 0; i < t; i++)
	{
		result = 0;
		minvalue = INF;
		for ( j = 0; j < 7; j++)
		{
			cin >> itemp;
			if (!(itemp%2))
			{
				result += itemp;
				if (minvalue > itemp)
				{
					minvalue = itemp;
				}
			}
		}
		cout << result << " " << minvalue << endl;
	}
```
