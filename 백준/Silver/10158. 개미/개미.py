import sys;input = sys.stdin.readline
w, h = map(int, input().split())
x, y = map(int, input().split())
t = int(input())
nx, ny = x + t % (2 * w), y + t % (2 * h)
if ny > h: ny = 2 * h - ny
if nx > w: nx = 2 * w - nx
print(abs(nx), abs(ny))
