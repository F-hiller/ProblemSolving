#include <bits/stdc++.h>
using namespace std;

vector<unordered_set<int>> v(9);
int solution(int N, int number)
{
    // init
    int answer = 0;
    int i, K, l, cur, fir, sec;

    // N을 붙여 나감
    int NN = N;
    for (i = 1; i < 9; i++)
    {
        v[i].insert(NN);
        NN = NN * 10 + N;
    }
    // N이 K번 사용되기 위해서는  i번 + K-i번의 사칙연산을 이용하면 된다.
    for (K = 2; K < 9; K++)
    {
        for (i = 1; i < K; i++)
        {
            for (auto j = v[i].begin(); j != v[i].end(); j++)
            {
                for (auto k = v[K - i].begin(); k != v[K - i].end(); k++)
                {
                    v[K].insert(*j + *k);
                    if (*j - *k > 0)
                    {
                        v[K].insert(*j - *k);
                    }
                    v[K].insert(*j * *k);
                    if (*k)
                    {
                        v[K].insert(*j / *k);
                    }
                }
            }
        }
    }
    for (i = 1; i < 9; i++)
    {
        if (v[i].find(number) != v[i].end())
        {
            return i;
        }
    }
    return -1;
}

// main function
int main()
{
    // fastio;
    int i, j, k;
    // init
    cout << solution(2, 11);

    return 0;
}
