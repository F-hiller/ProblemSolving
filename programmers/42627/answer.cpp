#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

struct comp_pq
{
    bool operator()(pii a, pii b)
    {
        return a.second > b.second;
    }
};
bool comp_sort(pii a, pii b)
{
    return a.first < b.first;
}

int solution(vector<vector<int>> jobs)
{
    int answer = 0;
    priority_queue<pii, vector<pii>, comp_pq> pq;
    vector<pii> jobs_pii;
    int i;
    int job_size = jobs.size();

    // set and sort
    for (auto job : jobs)
    {
        jobs_pii.push_back(pii(job[0], job[1]));
    }
    sort(jobs_pii.begin(), jobs_pii.end(), comp_sort);

    int cnt = 0;
    int end_time = 0;
    int index = 0;
    while (cnt < job_size)
    {
        while (index < job_size && jobs_pii[index].first <= end_time)
        {
            pq.push(jobs_pii[index++]);
        }
        if (pq.empty())
        {
            end_time = jobs_pii[index].first;
            continue;
        }
        pii top = pq.top();
        pq.pop();
        end_time += top.second;
        answer += end_time - top.first;
        cnt++;
    }

    return answer / job_size;
}