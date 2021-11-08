[BOJ 2953 - 나는 요리사다](https://www.acmicpc.net/problem/2953)   
```c++
int t, n, m, input1, input2;
int value = 0, num;
int main() {
	//init
	FastIO;
	int i, j, k;
	for ( i = 0; i < 5; i++)
	{
		int sum = 0;
		for ( j = 0; j < 4; j++)
		{
			cin >> input1;
			sum += input1;
		}
		if (sum > value)
		{
			value = sum;
			num = i + 1;
		}
	}
	cout << num << " " << value;
	
	return 0;
}
```
