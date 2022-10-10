import sys;input = sys.stdin.readline
N = int(input())
arr = list(map(int,input().split()))
new_arr = [0] * N
res = [-1] * N
count = [0] * 1000001
stack = [0]
for i in range(N): count[arr[i]] += 1
for i in range(N): new_arr[i] = count[arr[i]]
for i in range(1, N):
    while stack and new_arr[stack[-1]] < new_arr[i]:
        res[stack.pop()] = arr[i]
    stack.append(i)
print(*res)