import sys;input = sys.stdin.readline

def cal(a, b, oper):
    if oper == 0: return a + b
    if oper == 1: return a - b
    if oper == 2: return a * b
    return int(a / b)

def backtrack(curr, used, total):
    global MAX, MIN
    if curr == n:
        MAX = max(total, MAX)
        MIN = min(total, MIN)
        return
    for i in range(4):
        if operator[i] - used[i] == 0: continue
        used[i] += 1
        backtrack(curr + 1, used, cal(total, nums[curr], i))
        used[i] -= 1

n = int(input())
nums = list(map(int, input().split()))
operator = list(map(int, input().split()))
MAX, MIN = -987654321, 987654321
backtrack(1, [0, 0, 0, 0], nums[0])
print(f'{MAX}\n{MIN}')