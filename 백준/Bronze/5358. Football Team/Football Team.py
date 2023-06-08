while True:
    try:
        for i in input():
            if i=='i':print('e',end='')
            elif i=='e':print('i',end='')
            elif i=='I':print('E',end='')
            elif i=='E':print('I',end='')
            else:print(i,end='')
        print()
    except:break