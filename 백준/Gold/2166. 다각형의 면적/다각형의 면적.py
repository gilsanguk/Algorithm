import sys;input = sys.stdin.readline
N = int(input())
ans, X, Y = 0, [], []
for _ in range(N):
    x, y = map(int, input().split())
    X.append(x)
    Y.append(y)
for i in range(N): ans += (X[i - 1] * Y[i] - X[i] * Y[i - 1])
print(round(abs(ans)/2, 1))