#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

bool visited[101][101] = {
    0,
};
int dirY[4] = {-1, 0, 1, 0};
int dirX[4] = {0, 1, 0, -1};

int bfs(int y, int x, int &m, int &n, vector<vector<int>> &picture)
{
    int i;
    int cnt = 0;
    int cur_value = picture[y][x];
    queue<pii> q;
    q.push(pii(y, x));
    while (!q.empty())
    {
        pii front = q.front();
        q.pop();
        int frontY = front.first;
        int frontX = front.second;
        if ((-1 < frontY && frontY < m && -1 < frontX && frontX < n) && !visited[frontY][frontX] && picture[frontY][frontX] == cur_value)
        {
            visited[frontY][frontX] = 1;
            cnt++;
            for (i = 0; i < 4; i++)
            {
                q.push(pii(frontY + dirY[i], frontX + dirX[i]));
            }
        }
    }
    return cnt;
}

vector<int> solution(int m, int n, vector<vector<int>> picture)
{
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    int i, j;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (!visited[i][j] && picture[i][j] != 0)
            {
                int itemp = bfs(i, j, m, n, picture);
                max_size_of_one_area = max(max_size_of_one_area, itemp);
                number_of_area++;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}