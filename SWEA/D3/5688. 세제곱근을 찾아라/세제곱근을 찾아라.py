import math
for T in range(int(input())):
    n = int(input()) ** (1 / 3)
    print(f'#{T + 1}', round(n)) if math.isclose(n, round(n)) else print(f'#{T + 1}', -1)