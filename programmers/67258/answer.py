def solution(gems):
    gem_dict = {}
    for i in gems:
        if i in gem_dict:
            gem_dict[i] += 1
        else:
            gem_dict[i] = 1

    result_len = 987654321
    result_head = 0
    result_tail = 0

    cur_range = {}
    head = 0
    tail = 0
    while tail < len(gems):

        if gems[tail] in cur_range:
            cur_range[gems[tail]] += 1
        else:
            cur_range[gems[tail]] = 1

        while gems[head] in cur_range and cur_range[gems[head]] > 1:
            cur_range[gems[head]] -= 1
            head += 1
        if len(gem_dict) == len(cur_range) and result_len > tail-head+1:
            result_len = tail-head+1
            result_head = head
            result_tail = tail

        tail += 1

    answer = []
    answer.append(result_head+1)
    answer.append(result_tail+1)
    return answer
