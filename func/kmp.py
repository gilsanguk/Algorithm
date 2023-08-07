def kmp(t, p):
    n, m = len(t), len(p)
    lps = [0] * m
    i = 0
    for j in range(1, m):
        while i and p[i] != p[j]:
            i = lps[i-1]
        if p[i] == p[j]:
            i += 1
            lps[j] = i
    i, cnt = 0, 0
    for j in range(n):
        while i and p[i] != t[j]:
            i = lps[i-1]
        if p[i] == t[j]:
            i += 1
            if i == m:
                cnt += 1
                i = lps[i-1]
    return cnt
