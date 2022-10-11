import sys;input=sys.stdin.readline
def mat_mul(a, b):
    ret = [[0] * 2 for _ in range(2)]
    for i in range(2):
        for j in range(2):
            tmp = 0
            for k in range(2):
                tmp += a[i][k] * b[k][j]
            ret[i][j] = tmp % 1000000
    return ret

def mat_pow(Matrix, n):
    if n == 1: return Matrix
    if n % 2 == 0:
        return mat_pow(mat_mul(Matrix, Matrix), n >> 1)
    else:
        return mat_mul(mat_pow(Matrix, n - 1), Matrix)

N = int(input())
Matrix = [[1, 1], [1, 0]]
if N == 1: print(1)
else: print((mat_pow(Matrix, N - 1)[0][0]))