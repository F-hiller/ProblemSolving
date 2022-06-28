### 문제

[코딩테스트 연습 - 입국심사](https://programmers.co.kr/learn/courses/30/lessons/43238)

### 풀이

심사 시간이 정해져있으므로 특정 시간 T에 모든 사람이 통과할 수 있는지를 확인하고 이분 탐색을 통해 T를 찾아주면 된다.

1. i번째 심사원이 T 시간 동안 처리할 수 있는 사람의 수를 구한다
2. 1)에서 구한 모든 사람의 수를 더하면 T 시간 동안 통과한 사람의 수 cnt를 구할 수 있다.
3. n과 cnt를 비교하여 이분탐색을 진행한다.

### 개선할 점

처음에 right값 즉, 최대값의 범위를 long long의 최댓값으로 정해주었다. 하지만 조금 더 계산의 범위를 줄이려고 한다면 심사원의 최대값과 모든 인원수를 곱해주면 된다. 곱해진 값은 해당 문제에서 발생할 수 있는 최악의 경우이며 long long의 최대값 보다 작다.

- Code

```cpp
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
```
