# T개의 테스트 케이스 입력
for T in range(int(input())):
    lst = []
    n,word=input().split()
    for s in word:
        lst.append(s*int(n))
    print(''.join(lst))