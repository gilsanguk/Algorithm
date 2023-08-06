#include <iostream>
#include <queue>

using namespace std;

int N;
struct Point {
    int y, x, w;
    bool operator<(const Point &p) const {
        return w > p.w;
    }
};
int arr[100][100];
int memo[100][100];

void input() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        char tmp[100];
        scanf("%s", tmp);
        for (int j = 0; j < N; j++) {
            arr[i][j] = tmp[j] - '0';
            memo[i][j] = 987654321;
        }
    }
}

int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};
int dijkstra() {
    priority_queue<Point> pq;
    pq.push({0, 0, 0});
    memo[0][0] = 0;
    while (!pq.empty()) {
        Point cur = pq.top();
        pq.pop();
        if (cur.y == N - 1 && cur.x == N - 1) return cur.w;
        for (int i = 0; i < 4; i++) {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
            int nw = cur.w + arr[ny][nx];
            if (memo[ny][nx] > nw) {
                memo[ny][nx] = nw;
                pq.push({ny, nx, nw});
            }
        }
    }
    return -1;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        printf("#%d ", i);
        input();
        printf("%d\n", dijkstra());
    }
}