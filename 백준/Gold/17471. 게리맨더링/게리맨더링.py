import sys;input = sys.stdin.readline
def dfs(s, lst):
    global visited
    visited[s] = True
    if s in lst: lst.remove(s)
    for i in li[s]:
        if not visited[i] and i in lst:
            dfs(i, lst)
    visited[s] = False
    return lst

n = int(input())
population = [0] + list(map(int, input().split()))
arr, li, res = list(range(1,n+1)), [[]], 987654321
for _ in range(1,n+1):
    li.append(list(map(int,input().split()))[1:])
for i in range(1, 1<<(n-1)):
    tmp, tmp2 = [], []
    for j in range(n):
        if i & (1 << j): tmp.append(arr[j])
        else: tmp2.append(arr[j])
    visited = [False] * (n + 1)
    lst = dfs(tmp[0], tmp[:])
    if lst: continue
    lst = dfs(tmp2[0], tmp2[:])
    if lst: continue
    a, b = 0, 0
    for i in tmp: a += population[i]
    for i in tmp2: b += population[i]
    res = min(res, abs(a-b))

print(res if res != 987654321 else -1)