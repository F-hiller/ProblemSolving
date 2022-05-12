[2637번: 장난감 조립](https://www.acmicpc.net/problem/2637)

## 사고의 흐름

답을 출력하기 위한 과정을 다음과 같이 생각했다.

최종 부품을 만들기 위해 필요한 기본 부품의 갯수를 구하는 문제이므로 중간 부품들을 여러 부품들의 조합으로 다 바꾼후 계산하기로 했다. 

특정 부품이 어떤 부품들로 구성되어있는지를 나타내는 part배열과 실제로 최종 부품을 만들기 위해서 필요한 계산들을 진행하는 cnt배열을 선언해주었다.

따라서 part[i]에는 i번째 부품을 만들기 위해서는 어떤 부품이 얼마나 있어야하는지에 관한 정보가 벡터로 존재한다.

cnt[i]는 실제로 최종 부품을 만들기 위해서 i번째 부품이 어떤 기본 부품이 얼마나 있어야하는지에 관한 정보가 map형식으로 있다.

만약 cnt[i]의 하위 부품들 중 아직 계산하지 않은 것이 있다면 해당 부품의 기본 부품에 관한 정보를 먼저 계산하고 진행한다.

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
vector<pii> part[101];
map<int, int> cnt[101];

void pre(int index) {
	if (!cnt[index].empty())
	{
		return;
	}
	vector<pii> vec_part = part[index];
	if (vec_part.empty())
	{
		cnt[index].insert(pii(index, 1));
		return;
	}
	int i, j, needed_part_index;
	for (i = 0; i < vec_part.size(); i++)
	{
		needed_part_index = vec_part[i].first;
		if (cnt[needed_part_index].empty())
		{
			pre(needed_part_index);
		}
		for (auto iter = cnt[needed_part_index].begin(); iter != cnt[needed_part_index].end(); iter++)
		{
			if (cnt[index].find((*iter).first) == cnt[index].end())
			{
				cnt[index].insert(pii((*iter).first, (*iter).second * vec_part[i].second));
				continue;
			}
			cnt[index][(*iter).first] += (*iter).second * vec_part[i].second;
		}
	}
}

//main
int main() {
	//init
	FastIO;
	int i, j, k;
	//solution
	cin >> n >> m;
	for (i = 0; i < m; i++)
	{
		cin >> itemp1 >> itemp2 >> itemp3;
		part[itemp1].push_back(pii(itemp2, itemp3));
	}

	for (i = 1; i <= n; i++)
	{
		pre(i);
	}

	for (auto iter = cnt[n].begin(); iter != cnt[n].end(); iter++)
	{
		cout << (*iter).first << " " << (*iter).second << endl;
	}

	return 0;
}
```
