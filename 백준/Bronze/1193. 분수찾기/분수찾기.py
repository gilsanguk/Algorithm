x=int(input())
result=1
n=2
while x>result:
    result+=n
    n+=1

a=x-result+n-1
if n%2:
    print(f'{a}/{n-a}')
else:
    print(f'{n-a}/{a}')