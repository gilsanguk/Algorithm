import sys;input = sys.stdin.readline

def perm(k, l):
    global res
    if k == r:
        con = vow = 0
        for i in res:
            if i in vowel:
                vow += 1
        con = len(res) - vow
        if vow >= 1 and con >=2:
            print(''.join(res))
        return
    for i in range(l, n):
        if not visited[i]:
            res[k] = li[i]
            visited[i] = 1
            perm(k+1, i+1)
            visited[i] = 0

r, n = map(int,input().split())
li = list(input().split())
visited = [0] * n
res = [0] * r
vowel = ['a','e','i','o','u']
li.sort()
perm(0, 0)