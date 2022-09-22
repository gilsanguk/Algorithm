from collections import deque
n, k = map(int,input().split())
visited = [set() for _ in range(k + 1)]
visited[0].add(int(n))
q = deque([(n, 0)])
while q:
    n, cnt = q.popleft()
    if cnt == k: continue
    n = list(str(n))
    for i in range(len(n) - 1):
        for j in range(i + 1, len(n)):
            if i == 0 and n[j] == '0': continue
            n[i], n[j] = n[j], n[i]
            tmp = int(''.join(n))
            if tmp not in visited[cnt + 1]:
                q.append((tmp, cnt + 1))
                visited[cnt + 1].add(tmp)
            n[i], n[j] = n[j], n[i]

print(max(visited[k]) if visited[k] else -1)