import sys;input=sys.stdin.readline
def chess(y,x):
    idx1 = 0
    idx2 = 0
    for i in range(y, y+8):
        for j in range(x, x+8):
            if (i+j) & 1:
                if li[i][j] != 'B':
                    idx1 += 1
                if li[i][j] != 'W':
                    idx2 += 1
            else:
                if li[i][j] != 'W':
                    idx1 += 1
                if li[i][j] != 'B':
                    idx2 += 1
    return min(idx1,idx2)

def solve():
    cnt = []
    for y in range(n-7):
        for x in range(m-7):
            cnt.append(chess(y,x))
    return min(cnt)


n,m = map(int,input().split())
li = [list(input()) for _ in range(n)]
print(solve())
