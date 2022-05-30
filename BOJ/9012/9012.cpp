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
