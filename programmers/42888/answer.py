def solution(record):
    answer = []
    id_name_dict = {}
    for words in record:
        word_list = words.split(" ")
        command = word_list[0]
        uid = word_list[1]
        if command == "Leave":
            continue
        name = word_list[2]
        id_name_dict[uid] = name
    for words in record:
        word_list = words.split(" ")
        command = word_list[0]
        name = id_name_dict[word_list[1]]
        if command == "Leave":
            answer.append(name + "님이 나갔습니다.")
            continue
        if command == "Enter":
            answer.append(name + "님이 들어왔습니다.")

    return answer


print(solution(
    ["Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan"]))
