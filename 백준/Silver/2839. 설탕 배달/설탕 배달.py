def sugar_delivery(n):
    result=0
    while n>=0:
        if n%5 == 0:
            result += n//5
            return result
        else:
            n=n-3
            result+=1
    else:
        return -1

print(sugar_delivery(int(input())))