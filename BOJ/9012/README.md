[9012번: 괄호](https://www.acmicpc.net/problem/9012)

### 사고의 흐름

파이썬에서 제공하는 deque를 이용하여 스택을 사용하여 문제를 해결하였다.

```python
from collections import deque

dq = deque()
n = int(input())
for i in range(n):
    s = input()
    check = 1
    for j in s:
        if j == '(':
            dq.append(0)
        else:
            if len(dq) == 0:
                check = 0
                print("NO")
                dq.clear()
                break
            else:
                dq.pop()
    if check == 0:
        continue
    if len(dq) != 0:
        print("NO")
    else:
        print("YES")
    dq.clear()
```
