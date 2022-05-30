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
