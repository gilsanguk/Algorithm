import sys

li = [0]
for i in range(1,60):
    for _ in range(i):
        li.append(i)

n, m = map(int, sys.stdin.readline().split())
print(sum(li[n:m+1]))