# T개의 테스트 케이스 입력
for T in range(int(input())):

    #####################################

    #####################################

    # 테스트 케이스 번호가 포함된 출력
    print(f'#{T+1}')

    ###############################################################################
# 리스트 만들기
def make_list(n):
    lst=[]
    for i in range(1,n+1):
        lst.append(i)
    return lst

# 함수선언하여 테스트케이스
for T in range(int(input())):
    k = int(input())
    n = int(input())
    print()