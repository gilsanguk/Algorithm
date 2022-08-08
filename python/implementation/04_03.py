from sys import stdin

n, m = map(int, stdin.readline().split())
c, r, d = map(int, stdin.readline().split())
li = []
for _ in range(n):
    li.append(list(map(int, stdin.readline().split())))


def turn(d):
    if d == 0:
        return 3
    return d - 1


dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

tmp = 0
cnt = 0
while True:
    d = turn(d)
    if tmp == 4:
        d = turn(turn(d))
        if li[r + dy[d]][c + dx[d]] == 2:
            li[r][c] = 2
            r += dy[d]
            c += dx[d]
            d = turn(turn(d))
            tmp = 0
            continue
        else:
            print(cnt+1)
            break
    if li[r + dy[d]][c + dx[d]]:
        d = turn(d)
        tmp += 1
        continue
    else:
        li[r][c] = 2
        r += dy[d]
        c += dx[d]
        cnt += 1
        tmp = 0
        continue
