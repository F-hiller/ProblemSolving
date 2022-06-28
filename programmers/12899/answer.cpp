#include <bits/stdc++.h>
using namespace std;

// additional variables and functions
int all_arr[20] = {
    0,
};
int nextV[4] = {0, 0, 1, 2};
char realV[4] = {'0', '1', '2', '4'};
string solution(int n)
{
    string answer = "";
    int itemp = 1;
    int cnt = 0;
    while (true)
    {
        if (itemp > n)
        {
            break;
        }
        n -= itemp;
        all_arr[cnt] = 1;
        itemp *= 3;
        cnt++;
    }

    while (itemp)
    {
        int quo = n / itemp;
        int rem = n % itemp;
        if (quo == 3)
        {
            quo = 2;
        }
        n -= itemp * quo;
        all_arr[cnt] += quo;
        itemp /= 3;
        cnt--;
    }
    int i = 0;
    char ctemp;
    stack<char> s;
    while (i <= 19)
    {
        ctemp = realV[all_arr[i++]];
        if (ctemp == '0')
        {
            break;
        }
        s.push(ctemp);
    }
    while (!s.empty())
    {
        answer.push_back(s.top());
        s.pop();
    }

    return answer;
}

// main function
int main()
{
    // fastio;
    int i, j, k;
    // init
    for (i = 1; i < 20; i++)
    {
        cout << i << " " << solution(i) << endl;
    }

    return 0;
}
