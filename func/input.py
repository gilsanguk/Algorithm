import sys
# 텍스트 파일 인풋
sys.stdin = open('input.txt')
# 한가지 수 받기
n = int(sys.stdin.readline())
# 리스트로 받기
li = list(map(int, sys.stdin.readline().split()))
# 여러가지 수 받기
n, m = map(int, sys.stdin.readline().split())
# 2차원 배열 받기
li = []
for _ in range(n):
    li.append(list(map(int, sys.stdin.readline().split())))
# 한줄 씩 인풋 받을 때
li = [0] * n
for i in range(n):
    li[i] = int(sys.stdin.readline())
# 테스트 케이스 출력
for T in range(int(sys.stdin.readline())):

    print(f'#{T+1}')