#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 301
#define INF 987654321
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> piii;

// variables
int n, m, K, t, itemp1, itemp2;
int dirY4[] = {-1, 0, 1, 0};
int dirX4[] = {0, 1, 0, -1};

// additional variables and functions
int board[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
bool sol(int y, int x)
{
    int i, j;
    bool ret = 0;
    queue<pii> q;
    q.push(pii(y, x));

    while (!q.empty())
    {
        pii front = q.front();
        q.pop();
        int frontY = front.first;
        int frontX = front.second;
        if ((-1 < frontY && frontY < n && -1 < frontX && frontX < m) && !visited[frontY][frontX] && board[frontY][frontX] > 0)
        {
            visited[frontY][frontX] = 1;
            ret = 1;
            for (i = 0; i < 4; i++)
            {
                q.push(pii(dirY4[i] + frontY, dirX4[i] + frontX));
            }
        }
    }
    return ret;
}

// main function
int main()
{
    // fastio;
    int i, j, k;
    bool check = 0;

    // init
    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> itemp1;
            if (itemp1 == 0)
            {
                itemp1 = -1;
            }
            board[i][j] = itemp1;
        }
    }

    t = 0;
    while (1)
    {
        check = 0;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (board[i][j] == 0)
                {
                    board[i][j]--;
                    check = 1;
                }
            }
        }

        int cnt = 0;
        if (check)
        {
            // bfs func
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < m; j++)
                {
                    if (board[i][j] < 1 || visited[i][j])
                    {
                        continue;
                    }
                    cnt += sol(i, j);
                    if (cnt > 1)
                    {
                        cout << t;
                        exit(0);
                    }
                }
            }
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < m; j++)
                {
                    visited[i][j] = 0;
                }
            }
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (board[i][j] < 1)
                {
                    continue;
                }
                int melt_cnt = 0;
                for (k = 0; k < 4; k++)
                {
                    int y = i + dirY4[k];
                    int x = j + dirX4[k];
                    if ((-1 < y && y < n && -1 < x && x < m) && board[y][x] == -1)
                    {
                        melt_cnt++;
                    }
                }
                if (melt_cnt == 0)
                {
                    continue;
                }
                check = 1;
                board[i][j] -= melt_cnt;
                if (board[i][j] < 0)
                {
                    board[i][j] = 0;
                }
            }
        }

        t++;

        if (!check)
        {
            break;
        }
    }
    cout << 0;

    return 0;
}
