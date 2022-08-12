import sys;input = sys.stdin.readline
n = int(input())
brk_li = [0] * 1000001
cnt = 0
for i in range(n):
    a, b, c = map(int, input().split())
    if brk_li[a] == 0 and brk_li[b] == 0 and brk_li[c] == 0:
        cnt += 1
    brk_li[a], brk_li[b], brk_li[c] = brk_li[a]+1, brk_li[b]+1, brk_li[c]+1
print(cnt)