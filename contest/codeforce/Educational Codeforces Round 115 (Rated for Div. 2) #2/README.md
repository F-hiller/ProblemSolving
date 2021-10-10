```cpp
int t, n, m, input1, input2;
vector<bool> student[5];
vector<bool> visited;
int day[5];
bool solution(int fir, int sec) {
	int left = 0, right = 0;
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		if (student[fir][i] && student[sec][i]) { continue; }
		if (student[fir][i])
		{
			left++;
			visited[i] = 1;
			continue;
		}
		if (student[sec][i])
		{
			right++;
			visited[i] = 1;
			continue;
		}
		return 0;
	}
	return 1;
}
int main() {
	//init
	FastIO;
	cin >> t;
	int i, j, k;
	for (i = 0; i < t; i++)
	{
		cin >> n;
		for (j = 0; j < n; j++)
		{
			visited.push_back(0);
			for (k = 0; k < 5; k++)
			{
				cin >> input1;
				if (!input1) { day[k]++; }
				student[k].push_back(input1);
			}
		}
		int n2 = n / 2;
		bool check = 0;
		for (j = 0; j < 5; j++)
		{
			if (day[j] > n2) { continue; }
			for (k = j + 1; k < 5; k++)
			{
				if (day[k] > n2) { continue; }
				if (solution(j, k))
				{
					check = 1;
					break;
				}
			}
			if (check) { break; }
		}
		if (!check)
		{
			cout << "NO\n";
		}
		else
		{
			cout << "YES\n";
		}
		visited.clear();
		for (j = 0; j < 5; j++) { day[j] = 0; }
		for (j = 0; j < 5; j++) { student[j].clear(); }
	}
	return 0;
}
```
