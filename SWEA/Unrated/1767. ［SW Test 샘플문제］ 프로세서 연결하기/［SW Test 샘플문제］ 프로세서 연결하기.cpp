#include <iostream>
#include <vector>

using namespace std;

int T, N;
int board[13][13];
int connected, ans;
struct Core {
    int y, x;
};
vector<Core> cores;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
bool possible(int y, int x, int d) {
    y += dy[d], x += dx[d];
    while (y >= 0 && y < N && x >= 0 && x < N) {
        if (board[y][x]) return false;
        y += dy[d], x += dx[d];
    }
    return true;
}

int connect(int y, int x, int d) {
    int ret = 0;
    y += dy[d], x += dx[d];
    while (y >= 0 && y < N && x >= 0 && x < N) {
        board[y][x] = 1 - board[y][x];
        y += dy[d], x += dx[d];
        ret++;
    }
    return ret;
}

void backtrack(int curr, int cnt, int curr_sum) {
    if (cores.size() - curr + cnt < connected) return;
    if (curr == cores.size()) {
        if (connected < cnt) {
            connected = cnt;
            ans = curr_sum;
        }
        if (cnt == connected) {
            ans = min(ans, curr_sum);
        }
        return;
    }
    int y = cores[curr].y, x = cores[curr].x;
    for (int d = 0; d < 5; d++) {
        if (d == 4) {
            backtrack(curr + 1, cnt, curr_sum);
        } else if (possible(y, x, d)) {
            backtrack(curr + 1, cnt + 1, curr_sum + connect(y, x, d));
            connect(y, x, d);
        }
    }
}

void init() {
    connected = 0;
    ans = 987654321;
    cores.clear();
}

void input() {
    scanf("%d", &N);
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            scanf("%d", &board[y][x]);
            if (board[y][x] && y != 0 && y != N - 1 && x != 0 && x != N - 1) {
                cores.push_back({y, x});
            }
        }
    }
}

void solve() {
    init();
    input();
    backtrack(0, 0, 0);
    printf("%d\n", ans);
}

int main() {
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        printf("#%d ", i);
        solve();
    }
}