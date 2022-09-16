for T in range(int(input())):
    n, m = map(int, input().split())
    li = []
    home = []
    res = 0
    for y in range(n):
        li.append(list(map(int, input().split())))
        for x in range(n):
            if li[y][x]: home.append((y, x))

    for y in range(n):
        for x in range(n):
            table = [0] * (2 * n)
            for y1, x1 in home:
                table[abs(y - y1) + abs(x - x1)] += 1
            for i in range(1, 2*n):
                table[i] += table[i - 1]
            for i in range(2*n):
                fee = ((i+1) **2) + (i ** 2)
                if table[i] * m - fee >= 0 and res < table[i]:
                    res = table[i]

    print(f'#{T + 1}', res)