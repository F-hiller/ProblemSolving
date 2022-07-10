#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

struct comp
{
    bool operator()(pii a, pii b)
    {
        return a.second < b.second;
    }
};

int solution(vector<int> priorities, int location)
{
    int answer = 1, i;
    priority_queue<pii, vector<pii>, comp> pq;
    queue<pii> q;
    for (i = 0; i < priorities.size(); i++)
    {
        pq.push(pii(i, priorities[i]));
        q.push(pii(i, priorities[i]));
    }
    while (!q.empty())
    {
        pii front = q.front();
        q.pop();
        if (front.second == pq.top().second)
        {
            if (front.first == location)
            {
                break;
            }
            answer++;
            pq.pop();
            continue;
        }
        q.push(front);
    }

    return answer;
}