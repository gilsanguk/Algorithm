import sys
input = sys.stdin.readline

r, c = map(int, input().split())
n = int(input())
li = [(list(map(int, input().split()))) for _ in range(n)]
r_li, c_li = [0], [0]
for i in li:
    if i[0]:
        r_li.append(i[1])
    else:
        c_li.append(i[1])
r_li.sort()
c_li.sort()
r_li.append(r)
c_li.append(c)
for _ in range(len(r_li)-1):
    r_li.append(r_li[1]-r_li.pop(0))
for _ in range(len(c_li)-1):
    c_li.append(c_li[1]-c_li.pop(0))
r_li.pop(0)
c_li.pop(0)
max_v = 0
for i in r_li:
    for j in c_li:
        if max_v < i*j:
            max_v = i*j

print(max_v)