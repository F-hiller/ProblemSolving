[2448번 - 별 찍기 - 11](https://www.acmicpc.net/problem/2448)

## 사고의 흐름

어제 재귀를 통한 별 찍기를 배워서 적용해보았다. 재귀는 특정 조건을 통해서 더 이상 재귀를 호출하지 않는 시점을 잘 정하면 해결할 수 있다. 평소에 재귀를 잘 사용하지 않아서 다른 문제들을 풀어보며 익숙해져야겠다.

```cpp
int n, m, t, itemp1, itemp2;
char arr[3072][6144];

void solution(int y, int x, int len) {
	if (len == 3)
	{
		arr[y][x] = '*';
		arr[y+1][x-1] = '*';
		arr[y+1][x+1] = '*';
		for (int i = 0; i < 5; i++)
		{
			arr[y + 2][x - 2 + i] = '*';
		}
		return;
	}
	int half_len = len / 2;
	solution(y, x, half_len);
	solution(y + half_len, x + half_len, half_len);
	solution(y + half_len, x - half_len, half_len);
}

int main() {
	//init
	FastIO;
	//init
	int i, j, k;
	init();

	solution(0, n-1, n);

	for ( i = 0; i < n; i++)
	{
		for ( j = 0; j < 2 * n; j++)
		{
			if (arr[i][j] == NULL)
			{
				cout << " ";
				continue;
			}
			cout << arr[i][j];
		}
		cout << endl;
	}

	return 0;
}

void init() {
	int i, j, k;
	cin >> n;
}
```
