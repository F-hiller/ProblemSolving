```cpp
//additional variables
int arr1[4], arr2[4];
int sum1, sum2;
//main function
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//init
	int i, j, k, itemp;
	//solution
	for ( i = 0; i < 4; i++)
	{
		cin >> arr1[i];
		sum1 += arr1[i];
	}
	for (i = 0; i < 4; i++)
	{
		cin >> arr2[i];
		sum2 += arr2[i];
	}
	if (sum1>= sum2)
	{
		cout << sum1;
	}
	else
	{
		cout << sum2;
	}
	return 0;
}
```
