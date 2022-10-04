def getN(i, N):
    ret = N
    while i > 1:
        ret = ret * 10 + N
        i -= 1
    return ret

def solution(N, number):
    dp = [[] for _ in range(9)]
    dp[1] = [N]
    if N == number: return 1
    for i in range(2, 9):
        tmp = getN(i, N)
        if tmp == number: return i
        dp[i].append(tmp)
        for j in range(1, i):
            for num in dp[j]:
                if num == 0: continue
                for num2 in dp[i-j]:
                    if num2 == 0: continue
                    a, b, c, d = num + num2, num - num2, num * num2, num // num2
                    tmp = [a, b, c, d]
                    if number in tmp: return i
                    dp[i] += tmp
    return -1