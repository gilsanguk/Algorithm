import sys;input = sys.stdin.readline
n = int(input())
m = int(input())
txt = input().rstrip()
i, k, res = 0, 0, 0
while i < m-1:
    if txt[i:i+3] == 'IOI':
        i += 2
        k += 1
        if k >= n:
            res += 1
    else:
        i += 1
        k = 0
print(res)