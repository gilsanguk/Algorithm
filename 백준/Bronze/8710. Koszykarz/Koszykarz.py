a,b,c=map(int,input().split())
d=b-a
print(d//c if d%c==0 else d//c+1)