def getN(i, N):
    ret = N
    while i > 1:
        ret = ret * 10 + N
        i -= 1
    return ret
def solution(N, number):
    dp = [set() for _ in range(9)]
    dp[1] = [N]
    if N == number: return 1
    for i in range(2, 9):
        tmp = getN(i, N)
        if tmp == number: return i
        dp[i].add(tmp)
        for j in range(1, i):
            for num in dp[j]:
                if num == 0: continue
                for num2 in dp[i-j]:
                    if num2 == 0: continue
                    a, b, c, d = num + num2, num - num2, num * num2, num // num2
                    for tmp in [a, b, c, d]:
                        if number == tmp: return i
                        dp[i].add(tmp)
    return -1