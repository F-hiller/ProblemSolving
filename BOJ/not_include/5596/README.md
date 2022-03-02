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
#define DEBUG 0 //제출 시 0
#define endl    '\n'
#define INF 987654321
#define SHARING 100001

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

int dir4Y[] = { -1, 0, 1, 0 };
int dir4X[] = { 0, 1, 0, -1 };
int dir9Y[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dir9X[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int n, m, t, N, K;

//additional variables
int arr1[4], arr2[4];
int sum1, sum2;
//main function
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//init
	int i, j, k, itemp;
	//solution
	for ( i = 0; i < 4; i++)
	{
		cin >> arr1[i];
		sum1 += arr1[i];
	}
	for (i = 0; i < 4; i++)
	{
		cin >> arr2[i];
		sum2 += arr2[i];
	}
	if (sum1>= sum2)
	{
		cout << sum1;
	}
	else
	{
		cout << sum2;
	}
	return 0;
}
