MOD = 1000000007
N, a = map(int, input().split())
m = (pow(N, a, MOD) - pow(N, a - 1, MOD) + MOD) % MOD
k = (m + pow(N - 1, a, MOD)) % MOD
# 모듈러 역원, 페르마의 소정리
u = (1 - pow(N, MOD - 2, MOD) + MOD) % MOD
ans = m * (u * (pow(u, a - 1, MOD) - 1 + MOD) % MOD) % MOD * pow(u - 1, MOD - 2, MOD) % MOD
ans += k
print(N % MOD * ans % MOD)