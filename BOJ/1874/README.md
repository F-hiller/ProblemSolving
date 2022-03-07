[1874번: 스택 수열](https://www.acmicpc.net/problem/1874)

### 사고의 흐름

정답이 아닌 경우 NO 문자열만을 출력하고 종료해야하므로 출력 내용들은 deque에 담아두었다가 NO가 아닌 경우에 하나씩 꺼내면서 출력해주었다.

```python
from collections import deque
import sys
input = sys.stdin.readline

n = int(input().strip())
dq = deque()
stack = []
stack_size = 0
next_value = 1

for i in range(n):
    goal_value = int(input().strip())
    while next_value <= goal_value:
        dq.append('+')
        stack.append(next_value)
        stack_size += 1
        next_value += 1
    top = stack[stack_size - 1]
    while top != goal_value:
        if top < goal_value or stack_size == 0:
            print("NO")
            exit(0)
        dq.append('-')
        top = stack.pop()
        stack_size -= 1
    if stack_size == 0:
        print("NO")
        exit(0)
    dq.append('-')
    top = stack.pop()
    stack_size -= 1
for i in dq:
    print(i)
```
