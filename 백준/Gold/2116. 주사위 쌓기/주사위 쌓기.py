import sys; input=sys.stdin.readline
dct = {0: 5, 1: 3, 2: 4, 3: 1, 4: 2, 5: 0}
side = {
    0: [1, 2, 3, 4],
    1: [0, 2, 4, 5],
    2: [0, 1, 3, 5],
    3: [0, 2, 4, 5],
    4: [0, 1, 3, 5],
    5: [1, 2, 3, 4]
}
def dice(n, k):
    return max(map(lambda idx: li[n][idx], side[k]))


def solve():
    max_tot = 0
    for i in range(6):
        total = dice(0, i)
        tmp = i
        for j in range(1, len(li)):
            tmp = li[j].index(li[j - 1][dct[tmp]])
            total += dice(j, tmp)
        max_tot = max(total, max_tot)
    return max_tot


n = int(input())
li = [(list(map(int, input().split()))) for _ in range(n)]
print(solve())