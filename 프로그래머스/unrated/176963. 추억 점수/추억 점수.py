def solution(name, yearning, photo):
    answer = []
    for i in photo:
        result = 0
        for j in i:
            for k in range(len(name)):
                if j == name[k]:
                    result += yearning[k]
        answer.append(result)
    return answer