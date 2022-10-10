import sys;input = sys.stdin.readline
def dfs(node):
    tree[node] = -2
    for i in range(N):
        if node == tree[i]:
            dfs(i)

N = int(input())
tree = list(map(int,input().split()))
K = int(input())
cnt = 0
dfs(K)
for i in range(N):
    if tree[i] != -2 and i not in tree:
        cnt += 1
print(cnt)