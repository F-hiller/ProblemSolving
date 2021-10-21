[10973번: 이전 순열](https://www.acmicpc.net/problem/10973)

## 사고의 흐름

다음 순열 문제를 변형한 것이다.

역시 해결 방식은 같으며 부등호 방향만 수정해주면 된다.

1. 뒤에서부터 숫자가 점점 작아지는지 내림차순을 확인.
2. 내림차순 중에서 x보다 바로 아래 수를 찾아서 바꾼다.
3. 내림차순을 오름차순으로 정렬하여 출력한다.

1243 → 12**4** / 3 (4가 x)→ 12**4** / **3** (3이 x의 바로 아래 수)→ 123 / 4 → 1234

```cpp
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <list>
#include <set>
#include <stack>
#include <deque>
#include <tuple>
#include <sstream>
#include <cmath>
#include <map>
#define DEBUG 1
#define endl    '\n'
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX_VALUE 150000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> piii;

int t, n, m, input1, input2;
ll sum = 0;
int arr[10000];

void solution() {
	int i, j, k;
	int pre, cur;
	cur = arr[n - 1];
	for ( i = n - 2; i > -1; i--)
	{
		pre = cur;
		cur = arr[i];
		if (cur > pre)
		{
			for ( j = 0; j < i; j++)
			{
				cout << arr[j] << " ";
			}
			vector<int> v;
			for ( j = i + 1; j < n; j++)
			{
				v.push_back(arr[j]);
			}
			sort(v.begin(), v.end(), greater<int>());
			for ( j = 0; j < v.size(); j++)
			{
				if (v[j] < cur)
				{
					cout << v[j] << " ";
					v[j] = cur;
					break;
				}
			}
			for (j = 0; j < v.size(); j++)
			{
				cout << v[j] << " ";
			}
			return;
		}
	}
	cout << -1;
}

int main() {
	//init
	FastIO;
	int i, j, k;
	cin >> n;
	for ( i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	solution();

	return 0;
}
```
