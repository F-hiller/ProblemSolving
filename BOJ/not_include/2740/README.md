[2740번: 행렬 곱셈](https://www.acmicpc.net/problem/2740)

## 사고의 흐름

제목 그대로 두 행렬의 곱셈을 구현하는 문제이다. 행렬 쪽은 익숙하지 않았고 익혀둘 필요가 있어서 앞으로도 풀어볼 예정이다.

```cpp
int t, n, m, input1, input2;
int K;
int A[101][101], B[101][101], C[101][101];
int main() {
	//init
	FastIO;
	int i, j, k;
	cin >> n >> m;
	for ( i = 0; i < n; i++)
	{
		for ( j = 0; j < m; j++)
		{
			cin >> A[i][j];
		}
	}
	cin >> m >> K;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < K; j++)
		{
			cin >> B[i][j];
		}
	}
	//solve
	int sum = 0;
	for (i = 0; i < n; i++)
	{
		//A의 i번째 줄 선택
		for ( j = 0; j < K; j++)
		{
			//B의 j번째 줄 선택
			for ( k = 0; k < m; k++)
			{
				sum += (A[i][k] * B[k][j]);
			}
			C[i][j] = sum;
			sum = 0;
		}
	}
	//result
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < K; j++)
		{
			cout << C[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
```
