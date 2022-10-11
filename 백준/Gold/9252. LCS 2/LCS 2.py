import sys;input = sys.stdin.readline
sys.setrecursionlimit(10**7)
def LCS(s1, s2):
    if s1 == N or s2 == M: return 0, ''
    if dp[s1][s2][0] != -1: return dp[s1][s2]
    if S1[s1] == S2[s2]:
        n, s = LCS(s1 + 1, s2 + 1)
        return n + 1, s + S1[s1]
    n1, t1 = LCS(s1 + 1, s2)
    n2, t2 = LCS(s1, s2 + 1)
    dp[s1][s2] = (n1, t1) if n1 > n2 else (n2, t2)
    return dp[s1][s2]

S1 = input().rstrip()
S2 = input().rstrip()
N, M = len(S1), len(S2)
dp = [[(-1, '') for _ in range(M)] for _ in range(N)]
cnt, ans = LCS(0, 0)
print(cnt, ans[::-1])