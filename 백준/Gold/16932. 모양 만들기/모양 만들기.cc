#include <iostream>
#include <queue>
#include <map>

using namespace std;

int N, M;
int arr[1001][1001];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int ans, group;
struct Node {
    int y, x;
};
pair<int,int> visited[1001][1001];

void bfs(int y, int x) {
    queue<Node> q, q2;
    q.push({y, x});
    q2.push({y, x});
    int cnt = 1;
    visited[y][x] = {++group, 0};
    while (!q.empty()) {
        Node cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if (arr[ny][nx] == 0) continue;
            if (visited[ny][nx].first) continue;
            visited[ny][nx] = {group, 0};
            q.push({ny, nx});
            q2.push({ny, nx});
            cnt++;
        }
    }
    while(!q2.empty()) {
        Node cur = q2.front();
        q2.pop();
        visited[cur.y][cur.x].second = cnt;
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            scanf("%d", &arr[y][x]);
        }
    }
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (arr[y][x] == 1 && visited[y][x].first == 0) {
                bfs(y, x);
            }
        }
    }
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (arr[y][x] == 0) {
                int sum = 1;
                map<int, int> m;
                for (int i = 0; i < 4; i++) {
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                    if (arr[ny][nx] == 0) continue;
                    if (m[visited[ny][nx].first]) continue;
                    m[visited[ny][nx].first] = visited[ny][nx].second;
                }
                for (auto & it : m) {
                    sum += it.second;
                }
                ans = max(ans, sum);
            }
        }
    }
    printf("%d", ans);
}