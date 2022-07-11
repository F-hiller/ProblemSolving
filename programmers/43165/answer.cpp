#include <bits/stdc++.h>
using namespace std;

int dfs(int value, int index, vector<int> &v, int &target)
{
    if (index == v.size())
    {
        if (value == target)
        {
            return 1;
        }
        return 0;
    }
    return dfs(value + v[index], index + 1, v, target) + dfs(value - v[index], index + 1, v, target);
}

int solution(vector<int> numbers, int target)
{
    return dfs(0, 0, numbers, target);
}