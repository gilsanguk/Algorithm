Y,M,D=map(int, input().split())
y,m,d=map(int, input().split())
print(y-Y if M<m or (M==m and D<=d) else y-Y-1,y-Y+1,y-Y,sep='\n')