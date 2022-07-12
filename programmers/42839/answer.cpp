#include <bits/stdc++.h>
using namespace std;

bool visited[7];
set<int> ans;
bool isNotPrime[10000000] = {
    0,
};

void func(int index, string str, int select, int numbers_size, string &numbers)
{
    int i;
    if (index == numbers_size)
    {
        ans.insert(stoi(str));
        return;
    }
    for (i = 0; i < numbers_size; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            func(index + 1, str + numbers[i], select + 1, numbers_size, numbers);
            visited[i] = 0;
        }
        else
        {
            func(index + 1, str, select, numbers_size, numbers);
        }
    }
}

int solution(string numbers)
{
    int answer = 0, i, j;

    for (i = 2; i < 10000000; i++)
    {
        if (!isNotPrime[i])
        {
            for (j = i + i; j < 10000000; j += i)
            {
                isNotPrime[j] = 1;
            }
        }
    }

    func(0, "", 0, numbers.size(), numbers);

    for (auto value : ans)
    {
        if (value > 1 && !isNotPrime[value])
        {
            answer++;
        }
    }

    return answer;
}