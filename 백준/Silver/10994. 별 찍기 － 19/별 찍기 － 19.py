import sys;input=sys.stdin.readline
def star(n):
    if n == 1:
        return ['*']

    li = [['*']*((4*(n-1))+1) for _ in range(4*(n-1)+1)]
    for i in range(1,4*(n-1)):
        for j in range(1,4*(n-1)):
            li[i][j] = ' '
        
    tmp = star(n-1)
   

    for i in range(2,4*(n-1)-1):
        for j in range(2,4*(n-1)-1):
            li[i][j] = tmp[i-2][j-2]
            
    return li

n = int(input())
res = star(n)
for i in res:
    print(''.join(i))
print()