from collections import deque
import sys
input = sys.stdin.readline

init_str = input().strip()
n = int(input().strip())
dq1 = deque()
dq2 = deque()
for i in init_str:
    dq1.append(i)
for i in range(n):
    inputs = input().strip().split(' ')
    if inputs[0] == 'L' and len(dq1) != 0:
        dq2.appendleft(dq1.pop())
    elif inputs[0] == 'D' and len(dq2) != 0:
        dq1.append(dq2.popleft())
    elif inputs[0] == 'B' and len(dq1) != 0:
        dq1.pop()
    elif inputs[0] == 'P':
        dq1.append(inputs[1])
for i in dq1:
    print(i, end='')
for i in dq2:
    print(i, end='')
