#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int solution(int n, vector<vector<int>> edge)
{
    // init
    int i, j, k;
    int answer = 0;
    vector<vector<int>> node_list(n + 1);

    // set node with list
    for (i = 0; i < edge.size(); i++)
    {
        node_list[edge[i][0]].push_back(edge[i][1]);
        node_list[edge[i][1]].push_back(edge[i][0]);
    }
    // bfs
    queue<pii> q;
    vector<int> visited(n + 1);
    int max_value = 0;

    q.push(pii(1, 1));
    while (!q.empty())
    {
        pii front = q.front();
        q.pop();
        int index = front.first;
        int value = front.second;
        if (!visited[index])
        {
            visited[index] = value;
            for (i = 0; i < node_list[index].size(); i++)
            {
                q.push(pii(node_list[index][i], value + 1));
            }
            if (max_value < value)
            {
                max_value = value;
            }
        }
    }
    for (i = 1; i <= n; i++)
    {
        if (visited[i] == max_value)
        {
            answer++;
        }
    }
    return answer;
}
