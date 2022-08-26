import sys;input = sys.stdin.readline
def f(n,k):
    global cnt
    if n < k:
        return 0
    cnt += 1
    f(k, n-k)

n = int(input())
res, idx = 0, 0
for i in range(1,n+1):
    cnt = 2
    f(n, i)
    if res < cnt:
        res, idx = cnt, i
print(res)
print(n, end=' ')
while n >= idx:
    n, idx = idx, n-idx
    print(n, end=' ')
print(idx)
