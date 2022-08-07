# 테스트 케이스
for _ in range(int(input())):
    # 한가지 수 받기
    n = int(input())
    # 리스트로 받기
    li = list(map(int, input().split()))
    li.sort()
    result = li[1]-li[0]
    for i in range(2,n):
        result = max(result,li[i]-li[i-2])
    print(result)