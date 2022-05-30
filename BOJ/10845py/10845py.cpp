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
