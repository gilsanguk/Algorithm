def KMPSearch(pat, txt):
    M = len(pat)
    N = len(txt)
    lps = [0]*M
    cnt = 0
    computeLPS(pat, lps)
    i, j = 0, 0

    while i < N:
        if pat[j] == txt[i]:
            i += 1
            j += 1
        elif pat[j] != txt[i]:
            if j != 0:
                j = lps[j-1]
            else:
                i += 1

        if j == M:
            cnt += 1
            j = 0
    return N - (M-1)*cnt

def computeLPS(pat, lps):
    leng = 0
    i = 1
    while i < len(pat):
        if pat[i] == pat[leng]:
            leng += 1
            lps[i] = leng
            i += 1
        else:
            if leng != 0:
                leng = lps[leng-1]

            else:
                lps[i] = 0
                i += 1

for T in range(1,int(input())+1):
    t,p = input().split()
    print(f'#{T}', KMPSearch(p,t))
