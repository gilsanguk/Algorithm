from sys import stdin
# 한가지 수 받기
m = int(stdin.readline())
n = int(stdin.readline())
li = [0]*101
for i in range(1,101):
    li[i] = i**2
cnt = 0
new_lst = []
for i in li:
    if m<=i<=n:
        new_lst.append(i)
if new_lst:
    print(sum(new_lst))
    print(new_lst[0])
else:
    print(-1)