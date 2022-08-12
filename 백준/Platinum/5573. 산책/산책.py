import sys

h,w,n = map(int,sys.stdin.readline().split())

li = []
for _ in range(h):
    li.append(list(map(int,sys.stdin.readline().split())))

for i in range(h):
    li[i].append(2)
li.append([2]*(w+1))
lst = [[0 for _ in range(w+1)] for _ in range(h+1)]
for i in range(h):
    for j in range(w):
        if i==0 and j ==0:
            lst[i][j] = n-1
        lst[i+1][j] += lst[i][j]//2
        lst[i][j+1] += lst[i][j]//2
        if lst[i][j]%2:
            if li[i][j]:
                lst[i][j+1] += 1
            else:
                lst[i+1][j] += 1

for i in range(h):
    for j in range(w):
        li[i][j] = (li[i][j]+lst[i][j])%2

x, y = 0, 0
dy = [1,0]
dx = [0,1]
while True:
    y, x = y+dy[li[y][x]], x+dx[li[y][x]]
    if li[y][x] == 2:
        break
    
print(f'{y+1} {x+1}')
