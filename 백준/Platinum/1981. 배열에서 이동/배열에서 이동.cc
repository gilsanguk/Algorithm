#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N;
int arr[101][101];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
struct Node {
    int y, x;
};
queue<Node> q;
bool visited[101][101];
bool bfs(int s, int e) {
    memset(visited, false, sizeof(visited));
    q = queue<Node>();
    q.push({0, 0});
    visited[0][0] = true;
    while (!q.empty()) {
        int y = q.front().y, x = q.front().x;
        q.pop();
        if (arr[y][x] < s || arr[y][x] > e) continue;
        if (y == N - 1 && x == N - 1) return true;
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if (0 > ny || ny >= N || 0 > nx || nx >= N) continue;
            if (visited[ny][nx]) continue;
            visited[ny][nx] = true;
            q.push({ny, nx});
        }
    }
    return false;
}

bool isPossible(const int& minV, const int& maxV, int mid) {
    for (int i = minV; i <= maxV; i++) {
        if (bfs(i, i + mid)) return true;
    }
    return false;
}

void solve() {
    scanf("%d", &N);
    int maxV = 0, minV = 201;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            scanf("%d", &arr[y][x]);
            maxV = max(maxV, arr[y][x]), minV = min(minV, arr[y][x]);
        }
    }
    int l = 0, r = maxV - minV;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (isPossible(minV, maxV, mid)) r = mid - 1;
        else l = mid + 1;
    }
    printf("%d", l);
}


int main() {
    solve();
}