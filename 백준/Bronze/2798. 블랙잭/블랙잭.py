import sys;input = sys.stdin.readline
n, m = map(int, input().split())
li = list(map(int, input().split()))
subset,res = [], 0
for i in range(n):
    for j in range(i+1,n):
        for k in range(j+1,n):
            tmp = li[i]+li[j]+li[k]
            if tmp <= m:
                res = max(res,tmp)
print(res)