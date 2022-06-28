def get_pair(line):
    arr = line.split()
    end_time = arr[1].split(':')
    end_hour = int(end_time[0]) * 60 * 60 * 1000
    end_minute = int(end_time[1]) * 60 * 1000
    end_second = int(float(end_time[2]) * 1000)
    end_time = end_hour + end_minute + end_second
    duration = int(float(arr[2].split('s')[0]) * 1000) - 1
    return end_time, duration


change_list = []


def solution(lines):
    answer = 0

    for line in lines:
        change_list.append(get_pair(line))
    for i in range(len(change_list)):
        pair = change_list[i]
        start_time = pair[0]
        end_time = start_time + 999
        cnt = 1
        for j in range(i + 1, len(change_list)):
            after_pair = change_list[j]
            range_time = after_pair[0] - after_pair[1]
            if range_time <= end_time:
                cnt += 1
                print(1)
        if answer < cnt:
            answer = cnt
    return answer


inputs = ["2016-09-15 20:59:57.421 0.351s", "2016-09-15 20:59:58.233 1.181s", "2016-09-15 20:59:58.299 0.8s", "2016-09-15 20:59:58.688 1.041s", "2016-09-15 20:59:59.591 1.412s",
          "2016-09-15 21:00:00.464 1.466s", "2016-09-15 21:00:00.741 1.581s", "2016-09-15 21:00:00.748 2.31s",
          "2016-09-15 21:00:00.966 0.381s", "2016-09-15 21:00:02.066 2.62s"]
print(solution(inputs))
