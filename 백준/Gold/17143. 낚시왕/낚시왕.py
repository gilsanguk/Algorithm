import sys;input = sys.stdin.readline
dr = [0, -1, 1, 0, 0]
dc = [0, 0, 0, 1, -1]
rdir = [0, 2, 1, 4, 3]
def move(r, c, s, d):
    for i in range(s):
        r, c = r + dr[d], c + dc[d]
        if 1 > r or r > R:
            d = rdir[d]
            r = 2 if 1 > r else R - 1
        if 1 > c or c > C:
            d = rdir[d]
            c = 2 if 1 > c else C - 1
    return r, c, d

def solve():
    prev = {}
    for _ in range(M):
        r, c, s, d, z = map(int, input().split())
        prev[(r, c)] = (s, d, z)
    score = 0
    for i in range(1, C + 1):
        curr = {}
        hunt = (R + 1, 0)
        for r, c in prev:
            if c == i:
                if hunt[0] > r:
                    hunt = (r, c)
        if hunt[1]:
            score += prev[hunt][2]
            prev[hunt] = (0, 0, 0)
        for key, value in prev.items():
            r, c = key
            s, d, z = value
            if z == 0: continue
            ns = s % ((R - 1) * 2) if d < 3 else s % ((C - 1) * 2)
            r, c, d = move(r, c, ns, d)
            if (r, c) in curr and z < curr[r, c][2]: continue
            curr[(r, c)] = (s, d, z)
        prev = curr
    return score

R, C, M = map(int,input().split())
print(solve())