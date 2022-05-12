[2631번: 줄세우기](https://www.acmicpc.net/problem/2631)

## 사고의 흐름

LCS를 구하는 과정과 유사하다고 생각하며 문제를 풀었다.

오름차순으로 가장 긴 부분을 남겨두고 나머지 아이들을 옮겨주면 된다.

즉 5 1 3 2 4 가 있을 때 해당 배열에서 가장 긴 오름차순 형태는 (1 3 4) 또는 (1 2 4)이다. 이들의 길이가 3이므로 전체 길이 5에서 빼준 값인 2가 답이 되며 2번 옮겨서 오름차순을 만들 수 있다. 5와 2 또는 5와 3을 옮기면 된다.

```cpp
#include <bits/stdc++.h>
#define MAX_SIZE 1025
#define DEBUG 0
#define endl    '\n'
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> piii;

int n, m, K, itemp1, itemp2, itemp3;

//additional variables and functions
int arr[201];
int order[201];

void recur(int index, int max_order) {
	if (index == n)
	{
		return;
	}
	int i, j;
	for (i = index + 1; i < n; i++)
	{
		if (arr[i] >= arr[index] && order[i] <= max_order)
		{
			order[i] = max_order + 1;
			recur(i, max_order + 1);
		}
	}
}

//main
int main() {
	//init
	FastIO;
	int i, j, k;
	//solution
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
		order[i] = 1;
	}
	pii ptemp;
	for ( i = 0; i < n; i++)
	{
		recur(i, 1);
	}
	int result = order[0];
	for ( i = 1; i < n; i++)
	{
		if (result < order[i])
		{
			result = order[i];
		}
	}
	cout << n - result;
	return 0;
}
```
