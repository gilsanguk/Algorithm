import sys; input = sys.stdin.readline

def solve():
    cnt = 0
    while True:
        for i in range(n):
            if li[i] == max(li):
                cnt+=1
                li[i] = 0
                if i == m:
                    return cnt

for T in range(int(input())):
    n, m = map(int, input().split())
    li = list(map(int, input().split()))
    print(solve())