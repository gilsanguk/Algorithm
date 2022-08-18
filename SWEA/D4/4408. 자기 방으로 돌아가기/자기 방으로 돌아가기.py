for T in range(int(input())):
    li = [0]*401
    res = 0
    for _ in range(int(input())):
        s, e = map(int,input().split())
        if s > e:
            s, e = e, s
        if (s&0):
            s = s-1
        if (e&1):
            e = e+1
        for i in range(s,e+1):
            li[i] += 1
    for i in range(401):
        if res < li[i]:
            res = li[i]
    print(f'#{T+1} {res}')