[3040번: 백설 공주와 일곱 난쟁이](https://www.acmicpc.net/problem/3040)

```cpp
	//init
	int i, j, k, itemp;
	int sum = 0;
	//solution
	for ( i = 0; i < 9; i++)
	{
		cin >> itemp;
		sum += itemp;
		v.push_back(itemp);
	}
	sum -= 100;
	for ( i = 0; i < 9; i++)
	{
		for ( j = i+1; j < 9; j++)
		{
			if (v[i]+v[j] == sum)
			{
				for ( k = 0; k < 9; k++)
				{
					if (k != i && k != j)
					{
						cout << v[k] << endl;
					}
				}
				return 0;
			}
		}
	}
```
