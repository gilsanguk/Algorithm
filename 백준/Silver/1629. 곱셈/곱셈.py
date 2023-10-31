def my_pow(a, b):
    if b == 1:
        return a % C
    else:
        temp = my_pow(a, b//2)
        if b % 2 == 0:
            return temp * temp % C
        else:
            return temp * temp * a % C
        
A,B,C=map(int,input().split())
print(my_pow(A,B))