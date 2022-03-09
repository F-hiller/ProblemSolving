[10845번: 큐](https://www.acmicpc.net/problem/10845)

### 사고의 흐름

앞선 문제들과 마찬가지로 자료구조 중 하나인 큐를 구현하는 문제로 스택의 문제를 그래도 가져다가 변형하여 queue의 역할을 하는 변수 이름이 stack이다.

```python
from collections import deque
import sys
input = sys.stdin.readline

n = int(input().strip())
stack = deque()

for i in range(n):
    zero = input().strip().split(' ')
    fir = zero[0]
    if fir == "push":
        stack.append(zero[1])
    elif fir == "pop":
        if len(stack) == 0:
            print(-1)
        else:
            print(stack.popleft())
    elif fir == "size":
        print(len(stack))
    elif fir == "empty":
        if len(stack) == 0:
            print(1)
        else:
            print(0)
    elif fir == "front":
        if len(stack) == 0:
            print(-1)
        else:
            print(stack[0])
    elif fir == "back":
        if len(stack) == 0:
            print(-1)
        else:
            print(stack[len(stack) - 1])
```
