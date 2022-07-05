def solution(progresses, speeds):
    test = []
    answer = []

    for i in range(len(progresses)):
        if(100-progresses[i]) % speeds[i]:
            test.append((100-progresses[i])//speeds[i]+1)
            continue
        test.append((100-progresses[i])//speeds[i])

    index = 1
    pre = test[0]
    cnt = 1

    while(True):
        if index == len(test):
            break

        if pre >= test[index]:
            cnt += 1
        else:
            answer.append(cnt)
            pre = test[index]
            cnt = 1

        index += 1
    answer.append(cnt)

    return answer
