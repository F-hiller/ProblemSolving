[9076번: 점수 집계](https://www.acmicpc.net/problem/9076)

```jsx
//additional variables
vector<int> arr(5);

//main function
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//init
	int i, j, k;
	//solution
	cin >> t;
	for ( i = 0; i < t; i++)
	{
		for ( j = 0; j < 5; j++)
		{
			cin >> arr[j];
		}
		sort(arr.begin(), arr.end());
		if (arr[3]-arr[1] >= 4)
		{
			cout << "KIN" << endl;
			continue;
		}
		cout << arr[1] + arr[2] + arr[3] << endl;
	}
	return 0;
}
```
