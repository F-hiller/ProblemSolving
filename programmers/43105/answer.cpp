#include <bits/stdc++.h>
using namespace std;

int P[500][500] = {
    0,
};

int solution(vector<vector<int>> triangle)
{
    int answer = 0;
    int i, j;
    int left, right;
    P[0][0] = triangle[0][0];
    for (i = 1; i < triangle.size(); i++)
    {
        for (j = 0; j < triangle[i].size(); j++)
        {
            left = P[i - 1][j - 1];
            right = P[i - 1][j];
            if (j == 0)
            {
                P[i][j] = right + triangle[i][j];
                continue;
            }
            if (j == triangle[i].size() - 1)
            {
                P[i][j] = left + triangle[i][j];
                continue;
            }
            P[i][j] = max(left, right) + triangle[i][j];
        }
    }
    answer = *max_element(P[triangle.size() - 1], P[triangle.size() - 1] + triangle[triangle.size() - 1].size());
    return answer;
}