S=sum(map(int,input().split()))
C=int(input())
if C*2>S:print(S)
else:print(S-C*2)