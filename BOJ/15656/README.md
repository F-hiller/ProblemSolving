[15656번: N과 M (7)](https://www.acmicpc.net/problem/15656)

```cpp
int t, n, m, input1, input2;
vector<int> arr;
int ans[10];
bool visited[10];
void solution(int depth) {
	int i, j, k;
	if (depth == m)
	{
		for (i = 0; i < m; i++)
		{
			cout << ans[i] << " ";
		}
		cout << endl;
		return;
	}

	for (i = 0; i < n; i++)
	{
		ans[depth] = arr[i];
		visited[i] = 1;
		solution(depth + 1);
		visited[i] = 0;
	}

}

int main() {
	//init
	FastIO;
	int i, j, k;
	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		cin >> input1;
		arr.push_back(input1);
	}

	sort(arr.begin(), arr.end());

	solution(0);

	return 0;
}
```
