from collections import deque

def solve(li):
    rev = False
    for i in range(len(p)):
        if p[i] == 'R':
            rev = not rev
        else:
            try:
                if rev:
                    li.pop()
                else:
                    li.popleft()
            except:
                return 'error'
    if rev:
        li = deque(reversed(li))
    return '[' + ','.join(li) + ']'

for _ in range(int(input())):
    p = input()
    n = int(input())
    li = deque(input().strip('[]').split(','))
    if n == 0:
        li = []
    print(solve(li))
