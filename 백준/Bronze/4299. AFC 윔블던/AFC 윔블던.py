a,b=map(int,input().split())
c=a+b
if c%2 or c<0 or a-b<0:print(-1)
else:print(*sorted([c//2,a-c//2],reverse=True))