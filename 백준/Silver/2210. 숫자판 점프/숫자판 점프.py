# 델타 만들기
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]


# DFS 6번 까지
def dfs(num, y, x):

    # 6자리 수가 되면
    if len(num) == 6:
        # set에 추가
        num_set.add(num)
        return

    # 4방향 탐색
    for n in range(4):
        ny, nx = y + dy[n], x + dx[n]

        # 범위안에 있다면
        if 0 <= nx < 5 and 0 <= ny < 5:
            dfs(num + number_pan[ny][nx], ny, nx)

# 입력값 받기
number_pan = [list(map(str, input().split())) for _ in range(5)]
num_set = set()

for i in range(5):
    for j in range(5):
        dfs(number_pan[i][j], i, j)

print(len(num_set))