[15666번: N과 M (12)](https://www.acmicpc.net/problem/15666)

## 사고의 흐름

입력으로 들어온 숫자들을 중복해서 사용해도 되기에 각 숫자들의 갯수를 고려해줄 필요가 없다. 그래서 set을 사용해서 중복을 없애주고 백트래킹을 진행하였다. 어떤 수열에서 다음에 나올 숫자는 앞에서 골랐던 숫자보다 크거나 같아야한다는 조건이 있으므로 이를 for문에 넣어주기만 하면 된다.

```jsx
int n, m, t, N, K, itemp1, itemp2;
set<int> s;
int arr[8];
int ans[8];
int cnt;

void solution(int depth) {
	int i, j, k;
	if (depth == m)
	{
		for ( i = 0; i < m; i++)
		{
			cout << ans[i] << " ";
		}
		cout << endl;
		return;
	}
	if (depth == 0)
	{
		for (i = 0; i < cnt; i++)
		{
			ans[depth] = arr[i];
			solution(depth + 1);
		}
		return;
	}
	for ( i = 0; i < cnt; i++)
	{
		if (ans[depth-1] > arr[i])
		{
			continue;
		}
		ans[depth] = arr[i];
		solution(depth + 1);
	}
}

int main() {
	//init
	FastIO;
	//init
	int i, j, k;
	init();

	solution(0);

	return 0;
}

void init() {
	int i, j, k;
	cin >> n >> m;
	for ( i = 0; i < n; i++)
	{
		cin >> itemp1;
		s.insert(itemp1);
	}
	i = 0;
	for (auto iter = s.begin(); iter != s.end(); iter++)
	{
		arr[i++] = *iter;
	}
	cnt = s.size();
}
```
