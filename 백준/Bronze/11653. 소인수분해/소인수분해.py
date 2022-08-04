def div(N):
    for i in range(2,N+1):
        while N % i == 0:
            N = N//i
            print(i)

div(int(input()))