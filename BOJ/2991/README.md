[2991번: 사나운 개](https://www.acmicpc.net/problem/2991)

```cpp
int main() {
	//init
	FastIO;
	int a, b, c, d;
	int human[3];

	cin >> a >> b >> c >> d;
	cin >> human[0] >> human[1] >> human[2];
	int first_dog = (a + b);
	int second_dog = (c + d);

	int sum;
	for (i = 0; i < 3; i++)
	{
		sum = 0;
		int itemp1 = (human[i]) % first_dog;
		int itemp2 = (human[i]) % second_dog;
		if (0 < itemp1&&itemp1 <= a)
		{
			sum++;
		}
		if (0 < itemp2&&itemp2 <= c)
		{
			sum++;
		}
		cout << sum << endl;
	}

	return 0;
}
```
