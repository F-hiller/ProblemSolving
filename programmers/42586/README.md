---
title: "[프로그래머스] 기능개발 - 42586 (Python)"
date: 2022-07-05 16:09:03 +0900
categories: [ProblemSolving, Programmers]
tags: [queue, python, level2]
---

## 문제

- 코딩테스트 연습 - 기능개발

{% linkpreview "https://school.programmers.co.kr/learn/courses/30/lessons/42586" %}

## 풀이

문제의 유형은 큐를 쓰는 유형이었지만 정작 큐를 사용하지 않았다.

큐를 이용하면 어떻게 풀 수 있을가에 대해 생각해봤고 그 풀이 방식은 아래와 같다.

1. progresses의 인덱스 i에 대해서 (100-progresses[i]) / speeds[i] 를 진행했을 때
2. 나머지가 존재하면 몫에서 1을 더해준 값이 완료까지 남은 날짜이다.
   나머지가 없다면 몫이 완료까지 남은 날짜이다.
   이들을 배열 remains에 progresses와 같은 인덱스로 저장한다.
3. 큐 Q가 있을 때 remains에서 인덱스가 작은 순으로 Q에 넣어준다.
4. Q에 넣으려는 값(A)보다 Q의 front값이 작다면 A를 넣기 전의 len(Q)를 answer에 append해주고 Q를 비우고 A를 넣어준다.
5. remains의 모든 인덱스를 탐색했다면 마지막으로 len(Q)를 answer에 append해주면 끝이난다.

### 코드

```python
def solution(progresses, speeds):
    remains = []
    answer = []
    for i in range(len(progresses)):
        if(100-progresses[i])%speeds[i]:
            remains.append((100-progresses[i])//speeds[i]+1)
            continue
        remains.append((100-progresses[i])//speeds[i])

    index = 1
    pre = remains[0]
    cnt = 1
    while(True):
        if index == len(remains):
            break
        if pre >= remains[index]:
            cnt += 1
        else:
            answer.append(cnt)
            pre = remains[index]
            cnt = 1
        index += 1
    answer.append(cnt)
    return answer
```
