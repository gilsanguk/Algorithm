import sys
def KMP(t, p):
    n, m = len(t), len(p)
    lps = [0] * m
    LPS(p,lps)
    i, j = 0, 0
    cnt = 0
    li = []
    while i < n:
        if t[i] == p[j]:
            i += 1
            j += 1
        elif t[i] != p[j]:
            if j != 0:
                j = lps[j-1]
            else:
                i += 1
        if j == m:
            cnt += 1
            li.append(i-j+1) # 출력
            j = lps[j-1] # 다시 탐색
    return cnt,li

def LPS(p,lps):
    l = 0
    i = 1
    while i < len(p):
        if p[l] == p[i]:
            l += 1
            lps[i] = l
            i += 1
        else:
            if l != 0:
                l = lps[l-1]
            else:
                lps[i] = 0
                i += 1

t = input()
p = input()
cnt, li= KMP(t,p)
print(cnt)
print(*li)