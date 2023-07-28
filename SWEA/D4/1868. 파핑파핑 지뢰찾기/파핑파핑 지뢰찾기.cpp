#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[301][301];
int ans, N;
int dy[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dx[] = {0, 0, -1, 1, 1, -1, -1, 1};

bool isZero(int y, int x) {
    for (int i = 0; i < 8; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
        if (map[ny][nx] == -2) return false;
    }
    return true;
}

void click(int y, int x) {
    queue<pair<int, int>> q;
    q.push({y, x});
    map[y][x] = 0;
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int ny = curr.first + dy[i];
            int nx = curr.second + dx[i];
            if (ny < 0 || nx < 0 || ny >= N || nx >= N || map[ny][nx] != -1) continue;
            if (isZero(ny, nx)) q.push(make_pair(ny, nx));
            map[ny][nx] = 0;
        }
    }
}

void solve() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] != -1) continue;
            if (isZero(i, j)) {
                click(i, j);
                ans++;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == -1) ans++;
        }
    }
}

char str[301];
void input() {
    scanf("%d", &N);
    ans = 0;
    for (int y = 0; y < N; y++) {
        scanf("%s", str);
        for (int x = 0; x < N; x++) {
            if (str[x] == '.') map[y][x] = -1;
            else map[y][x] = -2;
        }
    }
}

int T;
int main() {
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        input();
        solve();
        printf("#%d %d\n", i, ans);
    }
}