def perm(k, r):
    if k == r:
        print(*order)
    else:
        for i in range(n):
            if visited[i]: continue
            order[k] = li[i]
            visited[i] = 1
            perm(k + 1, r)
            visited[i] = 0


def comb(k, res):
    if len(res) == r:
        print(*res)

    for i in range(k, n):
        comb(i + 1, res + [li[i]])


n, r = map(int, input().split())
li = [1, 2, 3, 4]
visited = [0] * n
order = [0] * r
# perm(0, r)
comb(0, [])
