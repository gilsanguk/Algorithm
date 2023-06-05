for i in range(n:=int(input())):
    print(i+1,end=' ')
    if not (i+1)%6:print('Go!',end=' ')
if n%6:print('Go!',end=' ')