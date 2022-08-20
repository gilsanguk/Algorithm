import sys;input=sys.stdin.readline

def no_z(li):
    for i in range(3):
        if li[i] == 0:
            return 0
    return sum(li)

def magic_square(res):
    for i in range(3):
        if sum(li[i]) == max(li[i]):
            continue
        for j in range(3):
            if li[i][j] == 0:
                li[i][j] = res - sum(li[i])
    for i in range(3):
        for j in range(3):
            if li[j][i] == 0:
                li[j][i] = res - (li[0][i] + li[1][i] + li[2][i])

def solve():
    tmp = []
    for i in range(3):
        tmp += [no_z(li[i]), no_z(c_li[i])]
    tmp += [no_z(l_dia), no_z(r_dia)]
    res = max(tmp)
    if res:
        magic_square(res)
    else:
        res = 0
        for r in range(3):
            for c in range(3):
                res += li[r][c]
        magic_square(res//2)
            

li = [(list(map(int, input().split()))) for _ in range(3)]
c_li = list(zip(*li))
l_dia,r_dia = [], []
for i in range(3):
    l_dia.append(li[i][i])
    r_dia.append(li[2-i][i])
solve()
for i in range(3):
    print(*li[i])