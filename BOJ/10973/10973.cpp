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
