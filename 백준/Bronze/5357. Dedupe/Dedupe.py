for i in range(int(input())):
    n=''
    for j in input():
        if j!=n:
            n=j
            print(j,end='')
    print()