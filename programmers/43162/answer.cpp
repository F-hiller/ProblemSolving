#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

bool visited[201] = {
    0,
};

void bfs(int start, int &n, vector<vector<int>> &computers)
{
    int i;
    queue<int> q;
    q.push(start);
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        if (!visited[front])
        {
            visited[front] = 1;
            for (i = 0; i < n; i++)
            {
                if (computers[front][i] == 1)
                {
                    q.push(i);
                }
            }
        }
    }
    return;
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            answer++;
            bfs(i, n, computers);
        }
    }
    return answer;
}