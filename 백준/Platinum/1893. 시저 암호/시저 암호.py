import sys;input = sys.stdin.readline


def kmp(t, p):
    n, m = len(t), len(p)
    lps = [0 for _ in range(m)]
    i = 0
    for j in range(1, m):
        while i and p[i] != p[j]:
            i = lps[i-1]
        if p[i] == p[j]:
            i += 1
            lps[j] = i
    cnt = 0
    i = 0
    for j in range(n):
        while i and p[i] != t[j]:
            i = lps[i-1]
        if p[i] == t[j]:
            i+=1
            if i == m:
                cnt += 1
                i = lps[i-1]
    return cnt

for _ in range(int(input())):
    li = list(input().rstrip())
    p = list(input().rstrip())
    t = list(input().rstrip())
    dct = {li[i]:li[i-1] for i in range(len(li))}
    i, res = 0, []
    while i < len(li):
        if kmp(t, p) == 1:
            res.append(i)
        for j in range(len(t)):
            t[j] = dct[t[j]]
        i += 1
    n = len(res)
    if n == 0:
        print("no solution")
    elif n == 1:
        print("unique:", res[0])
    else:
        print("ambiguous:", end="")
        for n in res:
            print("", n, end="")
        print()