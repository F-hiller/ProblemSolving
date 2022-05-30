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
