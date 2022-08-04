def solve(scores,N):
    avg=sum(scores)/N
    cnt=0
    for score in scores:
        if score>avg:
            cnt+=1
    return '{:.3f}'.format(round(float(cnt/N*100),3))


for T in range(int(input())):

    #####################################

    lst = list(map(int,input().split()))
    N = lst.pop(0)

    #####################################

    # 테스트 케이스 번호가 포함된 출력
    print(f'{solve(lst,N)}%')