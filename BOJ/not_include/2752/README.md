[2752번: 세수정렬](https://www.acmicpc.net/problem/2752)

```jsx
int n, m, t, N, K, itemp1, itemp2;
vector<int> v(3);

void solution() {
	int i, j, k;
	sort(v.begin(), v.end());
	cout << v[0] << " " << v[1] << " " << v[2];
}

int main() {
	//init
	FastIO;
	//init
	int i, j, k;
	init();

	solution();

	return 0;
}

void init() {
	int i, j, k;
	cin >> v[0] >> v[1] >> v[2];
}
```
