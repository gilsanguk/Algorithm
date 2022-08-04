N = int(input())
A = list(map(int,input().split()))

idx_lst = [0]
result = [-1]*N
for i in range(1,N):
    while idx_lst and A[idx_lst[-1]] < A[i]:
        result[idx_lst.pop()] = A[i]
    idx_lst.append(i)

print(*result)