import sys
input = sys.stdin.readline
n = int(input())
li = list(map(int, input().split()))
li.sort()
tmp = 1
for i in li:
    if i <= tmp:
        tmp += i
    else:
        break
print(tmp)