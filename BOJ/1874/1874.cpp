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
