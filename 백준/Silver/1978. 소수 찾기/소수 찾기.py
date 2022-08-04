def prime(lst):
    result = 0

    for num in lst:
        cnt = 0
        if num == 1:
            continue
        elif num == 2:
            result+=1
        else:
            for i in range(2,num):
                if num%i:
                    pass
                else:
                    cnt+=1
                    break
            if cnt == 0:
                result+=1

    return result

N = int(input())
lst = list(map(int,input().split()))
print(prime(lst))