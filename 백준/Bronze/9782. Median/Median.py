c=1
while a:=list(map(int,input().split())):
    n=a[0]
    if n==0:break
    b=a[n//2+1]if n%2 else(a[n//2]+a[n//2+1])/2
    print(f'Case {c}:',f'{b:.1f}')
    c+=1