#include <bits/stdc++.h>
using namespace std;
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

// variables
int n, m, K, itemp1, itemp2;

// additional variables and functions
int chess[10][10];
int ans[2];
bool right_down_cross[20], right_up_cross[20];
void sol(int y, int x, int cnt, bool is_white)
{
    if (x >= n)
    {
        y++;
        x = (x % 2 ? 0 : 1);
    }
    if (y >= n)
    {
        ans[is_white] = max(ans[is_white], cnt);
        return;
    }
    if (chess[y][x] == 1 && !right_down_cross[n + x - y] && !right_up_cross[x + y])
    {
        right_down_cross[n + x - y] = 1;
        right_up_cross[x + y] = 1;
        sol(y, x + 2, cnt + 1, is_white);
        right_down_cross[n + x - y] = 0;
        right_up_cross[x + y] = 0;
    }
    sol(y, x + 2, cnt, is_white);
    return;
}

// main function
int main()
{
    // fastio;
    int i, j, k;
    // init
    cin >> n;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> chess[i][j];
        }
    }

    sol(0, 0, 0, 0);
    sol(0, 1, 0, 1);

    cout << ans[0] + ans[1];

    return 0;
}
