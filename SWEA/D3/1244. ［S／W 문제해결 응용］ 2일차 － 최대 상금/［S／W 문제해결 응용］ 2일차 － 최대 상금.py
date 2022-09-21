from collections import deque

for T in range(int(input())):
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
                n[i], n[j] = n[j], n[i]
                tmp = int(''.join(n))
                if tmp not in visited[cnt + 1]:
                    q.append((tmp, cnt + 1))
                    visited[cnt + 1].add(tmp)
                n[i], n[j] = n[j], n[i]
    print(f'#{T+1}', max(visited[k]))