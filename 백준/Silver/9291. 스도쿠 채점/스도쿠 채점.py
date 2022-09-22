import sys;input = sys.stdin.readline
def row(li):
    for i in range(9):
        lst = []
        for j in range(9):
            tmp = li[i][j]
            if tmp in lst:
                return 0
            else:
                lst.append(tmp)
    return 1
def col(li):
    for i in range(9):
        lst = []
        for j in range(9):
            tmp = li[j][i]
            if tmp in lst:
                return 0
            else:
                lst.append(tmp)
    return 1
def box(li):
    for n in range(0,9,3):
        for m in range(0,9,3):
            lst = []
            for i in range(n,n+3):
                for j in range(m,m+3):
                    tmp = li[j][i]
                    if tmp in lst:
                        return 0
                    else:
                        lst.append(tmp)
    return 1

for T in range(int(input())):
    li = [(list(map(int, input().split()))) for _ in range(9)]
    input()
    res = (row(li) + col(li) + box(li)) // 3
    print(f'Case {T + 1}:', 'CORRECT' if res else 'INCORRECT')