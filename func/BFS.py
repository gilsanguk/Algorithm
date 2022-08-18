def BFS(z, y, x, li, queue, m, n, h):
    dz = [0, 0, 0, 0, -1, 1]
    dy = [-1, 1, 0, 0, 0, 0]
    dx = [0, 0, -1, 1, 0, 0]
    for i in range(6):
        if 0 <= z+dz[i] < h and 0 <= y+dy[i] < n and 0 <= x+dx[i] < m:
            if li[z+dz[i]][y + dy[i]][x + dx[i]] == 0:
                li[z+dz[i]][y + dy[i]][x + dx[i]] = 1
                queue.append((z+dz[i], y + dy[i], x + dx[i]))