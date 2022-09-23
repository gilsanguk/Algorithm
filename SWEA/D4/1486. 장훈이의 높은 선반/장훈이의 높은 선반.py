for T in range(int(input())):
    n, k = map(int, input().split())
    li = list(map(int, input().split()))
    res = 987654321
    dp = set()
    for i in range(n):
        num = li[i]
        now = {num}
        for j in dp:
            tmp = num+j
            if tmp >= res: continue
            if tmp >= k:
                res = min(res, tmp)
            now.add(tmp)
        for j in now:
            dp.add(j)
    print(f'#{T+1}', res-k)