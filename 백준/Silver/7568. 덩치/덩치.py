import sys; input = sys.stdin.readline

n = int(input())
li = []
for _ in range(n):
    li.append(list(map(int, input().split())))

for i in range(n):
    cnt = 1
    for j in range(n):
        if li[i][0] < li[j][0] and li[i][1] < li[j][1]:
            cnt += 1
    print(cnt, end=' ')