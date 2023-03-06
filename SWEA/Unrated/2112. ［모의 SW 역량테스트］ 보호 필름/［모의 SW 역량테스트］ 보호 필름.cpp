#include <iostream>
#include <cstring>

using namespace std;

int T, N, M, K;
int arr[14][21];
int changed[14];
int ans;

bool possible() {
    for (int x = 0; x < M; x++) {
        int cnt = 0;
        int prev = -1;
        for (int y = 0; y < N; y++) {
            int cur = changed[y] == -1 ? arr[y][x] : changed[y];
            if (cur == prev) {
                cnt++;
            } else {
                cnt = 1;
                prev = cur;
            }
            if (cnt >= K) {
                break;
            }
            if (y == N - 1) {
                return false;
            }
        }
    }
    return true;
}

void solve(int depth, int cnt) {
    if (depth > N || cnt > ans) return;
    if (possible()) {
        ans = min(ans, cnt);
    }
    solve(depth + 1, cnt);
    for (int i = 0; i < 2; i++) {
        changed[depth] = i;
        solve(depth + 1, cnt + 1);
    }
    changed[depth] = -1;
}

void init() {
    memset(changed, -1, sizeof(changed));
    ans = 987654321;
}

int main() {
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        init();
        scanf("%d %d %d", &N, &M, &K);
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                scanf("%d", &arr[y][x]);
            }
        }
        solve(0, 0);
        printf("#%d %d\n", t, ans);
    }
}