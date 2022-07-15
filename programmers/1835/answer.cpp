#include <bits/stdc++.h>
using namespace std;

bool isExisting[8];
vector<char> names;
int friendsToIndex(char c)
{
    int i;
    for (i = 0; i < 8; i++)
    {
        if (names[i] == c)
        {
            return i + 1;
        }
    }
}

int makeGroup(string group, int cnt, int &n, vector<string> &data)
{
    int i;
    int ret = 0;
    if (cnt == 8)
    {
        for (i = 0; i < n; i++)
        {
            char firstMan = data[i][0];
            char secondMan = data[i][2];
            char oper = data[i][3];
            int aimGap = data[i][4] - 48;

            int firstIndex = group.find(firstMan);
            int secondIndex = group.find(secondMan);

            int gap = max(firstIndex, secondIndex) - min(firstIndex, secondIndex) - 1;

            if ((oper == '=' && gap != aimGap) || (oper == '<' && gap >= aimGap) || (oper == '>' && gap <= aimGap))
            {
                return 0;
            }
        }
        return 1;
    }
    for (i = 0; i < 8; i++)
    {
        if (!isExisting[i])
        {
            isExisting[i] = 1;
            ret += makeGroup(group + names[i], cnt + 1, n, data);
            isExisting[i] = 0;
        }
    }
    return ret;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data)
{
    int i;
    int answer = 0;
    for (i = 0; i < 8; i++)
    {
        isExisting[i] = 0;
    }
    names = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};

    answer = makeGroup("", 0, n, data);

    return answer;
}