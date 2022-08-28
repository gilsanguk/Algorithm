def perm(k):
    if k == r:
        print(*order)
    else:
        for i in range(n):
            if not visited[i]:
                order[k] = li[i]
                visited[i] = 1
                perm(k + 1)
                visited[i] = 0

def comb(k, l):
    if k == r:
        print(*order)
    else:
        for i in range(l, n):
            if not visited[i]:
                order[k] = li[i]
                visited[i] = 1
                comb(k + 1, i+1)
                visited[i] = 0

# def comb(k, res):
#     if len(res) == r:
#         print(*res)
#         return

#     for i in range(k, n):
#         comb(i + 1, res + [li[i]])




n, r = map(int, input().split())
li = [1, 2, 3, 4]
visited = [0] * n
order = [0] * r
perm(0)
print()
comb(0, 0)
