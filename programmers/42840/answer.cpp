#include <bits/stdc++.h>
using namespace std;

vector<int> fir = {1, 2, 3, 4, 5};
vector<int> sec = {2, 1, 2, 3, 2, 4, 2, 5};
vector<int> thr = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers)
{
    vector<int> answer;
    int i, j, k;
    vector<int> scoreN = {0, 0, 0};
    for (i = 0; i < answers.size(); i++)
    {
        if (fir[i % fir.size()] == answers[i])
        {
            scoreN[0]++;
        }
        if (sec[i % sec.size()] == answers[i])
        {
            scoreN[1]++;
        }
        if (thr[i % thr.size()] == answers[i])
        {
            scoreN[2]++;
        }
    }
    int max_index = max_element(scoreN.begin(), scoreN.end()) - scoreN.begin();
    for (i = 0; i < 3; i++)
    {
        if (scoreN[i] == scoreN[max_index])
        {
            answer.push_back(i + 1);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}