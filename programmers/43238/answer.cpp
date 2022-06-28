#include <bits/stdc++.h>
using namespace std;

// additional variables and functions
long long solution(int n, vector<int> times)
{
    int t = times.size(), i, j, k;
    long long answer;
    long long left, right, mid, cnt;
    left = 0, right = times.back() * ((long long)n);

    sort(times.begin(), times.end());
    while (left <= right)
    {
        cnt = 0;
        mid = (left + right) / 2;
        for (i = 0; i < t; i++)
        {
            cnt += mid / times[i];
        }
        if (n <= cnt)
        {
            answer = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return answer;
}

// main function
int main()
{
    // fastio;
    int i, j, k;
    // init
    vector<int> v;
    v.push_back(7);
    v.push_back(10);

    cout << solution(6, v);

    return 0;
}
