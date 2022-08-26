for T in range(int(input())):
    n,m =map(int, input().split())
    print(f'#{T + 1}', ((n // m + 1) ** (n % m)) * ((n // m) ** (m - (n % m))))