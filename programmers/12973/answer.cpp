#include <bits/stdc++.h>
using namespace std;

int solution(string s)
{
    int answer = -1;
    int i;
    stack<char> stk;

    stk.push(s[0]);
    for (i = 1; i < s.size(); i++)
    {
        if (stk.empty())
        {
            stk.push(s[i]);
            continue;
        }
        if (stk.top() == s[i])
        {
            stk.pop();
            continue;
        }
        stk.push(s[i]);
    }
    answer = stk.empty() ? 1 : 0;

    return answer;
}