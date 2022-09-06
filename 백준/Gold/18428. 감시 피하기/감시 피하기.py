import sys;input = sys.stdin.readline
dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]
def check():
    for teacher in teachers:
        for i in range(4):
            y, x = teacher
            while True:
                y, x = y + dy[i], x + dx[i]
                if y < 0 or x < 0 or y >= n or x >= n or li[y][x] == 'O':
                    break
                if li[y][x] == 'S':
                    return False
    return True

def solve(k):
    if k == 3:
        if check():
            print("YES")
            exit(0)
        return
    for y in range(n):
        for x in range(n):
            if li[y][x] == 'X':
                li[y][x] = 'O'
                solve(k + 1)
                li[y][x] = 'X'

n = int(input())
li = [list(input().split()) for _ in range(n)]
teachers = []
for y in range(n):
    for x in range(n):
        if li[y][x] == 'T':
            teachers.append((y, x))
solve(0)
print('NO')