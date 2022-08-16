import sys;input=sys.stdin.readline
def hanoi(n, src, dst, via, cnt):
    if n == 1:
        print(f'{src} {dst}')
    else:
        hanoi(n-1, src, via, dst, cnt)
        print(f'{src} {dst}')
        hanoi(n-1, via, dst, src, cnt)

n = int(input())
print(2**n - 1)
hanoi(n, 1, 3, 2, 0)