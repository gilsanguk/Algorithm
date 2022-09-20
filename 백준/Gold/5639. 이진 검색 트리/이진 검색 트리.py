import sys;input = sys.stdin.readline;sys.setrecursionlimit(10**7)
def dfs(s, e):
    if s > e: return
    tmp = e + 1
    for i in range(s + 1, e + 1):
        if tree[s] < tree[i]:
            tmp = i
            break
    dfs(s + 1, tmp - 1)
    dfs(tmp, e)

    print(tree[s])

tree = []
while True:
    try:
        tree.append(int(input()))
    except:
        break
dfs(0, len(tree) - 1)