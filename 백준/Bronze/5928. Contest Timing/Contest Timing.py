d,h,m=map(int,input().split())
a=d*24*60+h*60+m-16511
print(a if a>=0 else -1)