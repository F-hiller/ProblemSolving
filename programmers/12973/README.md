---
title: "[프로그래머스] 짝지어 제거하기 - 12973"
date: 2022-07-03 14:50:00 +0900
categories: [ProblemSolving, Programmers]
tags: [stack, cpp, level2] # TAG names should always be lowercase
---

### 문제

[코딩테스트 연습 - 짝지어 제거하기](https://programmers.co.kr/learn/courses/30/lessons/12973)

### 풀이

문자열에서 같은 문자가 붙어있으면 지워나가며 모든 문자를 지울 수 있는지 확인하는 문제이다.

문제에서는 해결을 위한 자료구조로 stack을 생각해냈는지가 중요했다.

abba라는 문자열이 있다고 할 때 bb를 지우고 나면 왼쪽 a(이하 a1)와 오른쪽 a(이하 a2)가 만나서 지워진다. a2 입장에서 볼 때 a1과 만난다는 것을 확인할 때 필요한 정보는 bb 이전에 오는 문자에 관한 정보이다. 즉 과거의 지워지지 않은 문자들을 index순서대로 쌓아두는 방식이 필요한데 이 때 필요한 것이 stack이다.

1. 문자열 s를 index 순으로 진행한다. index가 끝나면 4)로 간다.

2-1. stack이 비어있으면 stack에 s[index]를 넣고 1)로 간다.

2-2. stack에 문자가 있다면 stack의 top과 s[index]를 비교한다.

3-1. top==s[index]면 top을 stack에서 지우고 1)로 간다.

3-2. top≠s[index]면 stack에 s[index]를 넣고 1)로 간다.

1. stack이 비었으면 모든 문자를 지운 것이므로 answer = 1, stack이 남아있으면 answer = 0이다.

- Code

```cpp
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
```
