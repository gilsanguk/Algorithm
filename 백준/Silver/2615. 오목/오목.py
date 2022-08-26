import sys;input = sys.stdin.readline

def row(r, c):
    if c > 14:
        return 0
    for i in range(1, 5):
        if li[r][c + i] != li[r][c]:
            return 0
    if c < 14:
        if li[r][c + 5] == li[r][c]:
            return 0
    if c > 0:
        if li[r][c - 1] == li[r][c]:
            return 0
    return 1


def col(r, c):
    if r > 14:
        return 0
    for i in range(1, 5):
        if li[r + i][c] != li[r][c]:
            return 0
    if r < 14:
        if li[r + 5][c] == li[r][c]:
            return 0
    if r > 0:
        if li[r - 1][c] == li[r][c]:
            return 0
    return 1


def r_dia(r, c):
    if r > 14 or c > 14:
        return 0
    for i in range(1, 5):
        if li[r + i][c + i] != li[r][c]:
            return 0
    if r < 14 and c < 14:
        if li[r + 5][c + 5] == li[r][c]:
            return 0
    if r > 0 and c > 0:
        if li[r - 1][c - 1] == li[r][c]:
            return 0
    return 1


def l_dia(r, c):
    if r < 4 or c > 14:
        return 0
    for i in range(1, 5):
        if li[r - i][c + i] != li[r][c]:
            return 0
    if r > 4 and c < 14:
        if li[r - 5][c + 5] == li[r][c]:
            return 0
    if c > 0:
        if li[r + 1][c - 1] == li[r][c]:
            return 0
    return 1


def solve():
    for r in range(19):
        for c in range(19):
            if li[r][c] != 0:
                if row(r, c) or col(r, c) or r_dia(r, c) or l_dia(r, c):
                    print(li[r][c])
                    print(r + 1, c + 1)
                    return 0
    print(0)


li = [(list(map(int, input().split()))) for _ in range(19)]
solve()
