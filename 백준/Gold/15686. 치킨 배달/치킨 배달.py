from itertools import combinations

# 치킨과 집 사이의 거리 구하기
def distance(chicken_house):
    home_chicken = 0
    for i in range(N):
        for j in range(N):
            if maps[i][j] == 1:
                a = 100
                for k in range(M):
                    b = abs(i-chicken_house[k][0]) + abs(j-chicken_house[k][1])
                    a = min(a, b)
                home_chicken += a
    return home_chicken

# 입력값 받기
N, M = map(int, input().split())
maps = [list(map(int, input().split())) for i in range(N)]
chicken = []
for i in range(N):
    for j in range(N):
        if maps[i][j] == 2:
            chicken.append((i, j))

# 치킨 조합으로 만들기
chicken_set = list(combinations(chicken,M))
min_result = 987654321


# 이제 뭐가 나은지 확인하기
for i in chicken_set:
    result = distance(i)
    if min_result > result:
        min_result = result

print(min_result)