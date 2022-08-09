import sys

n = int(sys.stdin.readline())
li = [0]*n
cnt = 0
for i in range(n):
    li[i] = int(sys.stdin.readline())

for i in range(n-1,0,-1):
    while li[i] <= li[i-1]:
        li[i-1] -= 1
        cnt += 1

print(cnt)