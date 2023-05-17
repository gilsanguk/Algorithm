v=['a','e','i','o','u']
while True:
    if(a:=input().lower())=='#':break
    print(sum([a.count(i) for i in v]))