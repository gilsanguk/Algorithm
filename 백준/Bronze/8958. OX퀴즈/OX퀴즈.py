for T in range(int(input())):
    OX = list(input())
    result = 0
    tmp = 0
    for i in range(1,len(OX)+1):
        if OX.pop(0)=='O':
            result+=1+tmp
            tmp+=1
        else:
            tmp=0

    print(result)