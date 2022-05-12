[2632번: 피자판매](https://www.acmicpc.net/problem/2632)

## 사고의 흐름

누적합을 사용하면 해결할 수 있다. 하지만 누적합을 사용해보자는 생각은 하지 못했고

큐, 3중 for문을 이용해서 해결해보려다가 실패하였다. 

수의 범위가 1000이하이므로 N^2의 방식으로도 충분히 해결가능하다.

```cpp
#include <bits/stdc++.h>
#define MAX_SIZE 2000001
#define INF 987654321
#define DEBUG 0
#define endl    '\n'
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> piii;

int n, m, K, itemp1, itemp2, itemp3;

//additional variables and functions
int A[1001], B[1001];
int pizza, sum, sum2, result;
int pizzaA[MAX_SIZE], pizzaB[MAX_SIZE];

//main
int main() {
	//init
	FastIO;
	int i, j, k;
	//solution
	cin >> pizza >> n >> m;
	for (i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	for (i = 0; i < m; i++)
	{
		cin >> B[i];
	}
	sum2 = 0;
	for ( i = 0; i < n; i++)
	{
		// index i
		sum = 0;
		for ( j = 0; j < n - 1; j++)
		{
			//몇번째 누적합 j
			sum += A[(i + j) % n];
			pizzaA[sum]++;
		}
		sum2 += A[i];
	}
	pizzaA[sum2]++;
	sum2 = 0;
	for (i = 0; i < m; i++)
	{
		sum = 0;
		for (j = 0; j < m - 1; j++)
		{
			sum += B[(i + j) % m];
			pizzaB[sum]++;
		}
		sum2 += B[i];
	}
	pizzaB[sum2]++;
	for (i = 0; i < pizza; i++)
	{
		result += (pizzaA[i] * pizzaB[pizza - i]);
	}
	result += (pizzaA[pizza] + pizzaB[pizza]);

	cout << result;

	return 0;
}
```
