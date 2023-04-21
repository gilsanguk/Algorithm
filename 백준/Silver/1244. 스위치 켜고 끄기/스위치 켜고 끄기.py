import sys;

n = int(sys.stdin.readline())
lst = list(map(int, sys.stdin.readline().split()))
m = int(sys.stdin.readline())
lst.insert(0, 9)
li = []
for _ in range(m):
    li.append(list(map(int, sys.stdin.readline().split())))
for i in li:
    if i[0] == 1:
        tmp = tmp_2 = i[1]
        while tmp <= n:
            lst[tmp] = (lst[tmp] + 1) % 2
            tmp += tmp_2
    if i[0] == 2:
        lst[i[1]] = (lst[i[1]] + 1) % 2
        tmp = 1
        while 0 <= i[1] - tmp and i[1] + tmp <= n and lst[i[1] - tmp] == lst[i[1] + tmp]:
            lst[i[1] - tmp], lst[i[1] + tmp] = (lst[i[1] - tmp] + 1) % 2, (lst[i[1] + tmp] + 1) % 2
            tmp += 1

for i in range(1, n + 1):
    print(lst[i], end=' ')
    if i % 20 == 0:
        print()
