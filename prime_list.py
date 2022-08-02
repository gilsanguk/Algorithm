def prime_list(N):
    new_lst = [2]
    for i in range(3,N):
        for j in range(2,i):
            if N % j == 0:
                break
        new_lst.append(i)

    return new_lst