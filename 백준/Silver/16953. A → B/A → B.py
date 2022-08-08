from sys import stdin

n, m = map(int,stdin.readline().split())

def ab(n,m):
    cnt = 1
    while m>=n:
        if m == n:
            return cnt
        if m%2 == 0:
            m = m//2
            cnt += 1
        elif str(m)[-1] == '1':
            m = m//10
            cnt += 1
        else:
            return -1
    return -1

    
print(ab(n,m))