[5543번: 상근날드](https://www.acmicpc.net/problem/5543)

```jsx
void init() {
	int i, j, k;
	cin >> itemp1 >> itemp2 >> itemp3;
	result = min(min(itemp1, itemp2), itemp3);
	cin >> itemp1 >> itemp2;
	result += min(itemp1, itemp2);
	cout << result-50;
}
```
