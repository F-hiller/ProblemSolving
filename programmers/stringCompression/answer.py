def solution(s):
    s_len = len(s)
    answer = s_len
    # i는 끊을 단어 수
    for block_len in range(1, s_len // 2 + 1):
        # 압축된 길이를 기록
        loop_result = ""
        prev = s[0:block_len]
        cnt = 1
        for cur_index in range(block_len, s_len, block_len):
            # 이전 쌍과 비교해서 같으면 압축, 내용 저장
            if prev == s[cur_index:cur_index + block_len]:
                cnt += 1
                continue
            # 이전 쌍과 다르고 앞에 저장된 내용이 있다면 결과에 반영
            if cnt > 1:
                loop_result += str(cnt)
            loop_result += prev
            prev = s[cur_index:cur_index + block_len]
            cnt = 1
        # 마지막 쌍 비교해서 반영
        if cnt > 1:
            loop_result += str(cnt)
        loop_result += prev
        # 결과 비교
        if answer > len(loop_result):
            answer = len(loop_result)
    return answer
