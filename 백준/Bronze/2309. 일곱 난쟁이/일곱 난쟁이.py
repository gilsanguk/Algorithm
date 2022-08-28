import sys;input = sys.stdin.readline
def comb(k, l, cnt):
    global answer
    if cnt > 100:
        return
    if k == 7:
        if cnt == 100:
            answer = res[:]
        return
    for i in range(l, 9):
        if not visited[i]:
            visited[i] = 1
            res.append(li[i])
            comb(k+1, i+1, cnt+li[i])
            res.remove(li[i])
            visited[i] = 0


li = [int(input()) for _ in range(9)]
visited = [0] * 9
res = []
answer = []
comb(0, 0, 0)
answer.sort()
for i in range(7):
    print(answer[i])