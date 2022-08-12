for k in range(10):
    T = int(input())
    li = []
    for _ in range(100):
        li.append(list(map(int, input().split())))
    max_v = 0
    for r in range(100):
        tmp = 0
        for c in li[r]:
            tmp += c
        if max_v < tmp:
            max_v = tmp

    for c in range(100):
        tmp = 0
        for r in range(100):
            tmp += li[r][c]
        if max_v < tmp:
            max_v = tmp
    r, c, i, tmp = 0, 0, 0, 0
    while i < 100:
        tmp += li[r + i][c + i]
        i += 1
    if max_v < tmp:
        max_v = tmp
    r, c, i, tmp = 99, 0, 0, 0
    while i < 100:
        tmp += li[r - i][c + i]
        i += 1
    if max_v < tmp:
        max_v = tmp

    print(f'#{T} {max_v}')