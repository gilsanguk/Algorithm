import sys;input = sys.stdin.readline


def perm(m, k):
    if m == k:
        print(*order)
    else:
        for i in range(n):
            if visited[i]:
                continue
            order[m] = li[i]
            visited[i] = 1
            perm(m + 1, k)
            visited[i] = 0


n, k = map(int, input().split())
li = list(range(1, n + 1))
visited = [0] * n
order = [0] * k
perm(0, k)