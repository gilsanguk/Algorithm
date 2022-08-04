def snail(A,B,V):
    result = (V-A)//(A-B)
    if (V-A)%(A-B):
        result+=1
    return result+1

A, B, V = map(int,input().split())
print(snail(A, B, V))