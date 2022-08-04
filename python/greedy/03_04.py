from sys import stdin

n, k = map(int, stdin.readline().split())
# 변수를 0으로 선언
cnt=0
# n이 1이 될 때까지 반복
while n!=1:
    #k로 나누어 떨어 지지 않는다면 -1
    if n%k:
        n-=1
        cnt+=1
    #k 로 나누어 떨어진다면 나누기
    else:
        n = n//k
        cnt+=1
print(cnt)