import sys

n, m = map(int, sys.stdin.readline().split())
li = []
for _ in range(n):
    li.append(list(map(int, sys.stdin.readline().split())))
li.sort(key=lambda x:(x[1],x[2],x[3]), reverse=True)

for i in range(len(li)):
    if li[i][0] == m:
        result = i+1
        while li[i][1:] == li[i-1][1:]:
            result -= 1
            i-=1

print(result)