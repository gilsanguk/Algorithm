#include <iostream>
#include <cstring>

using namespace std;

int N, M;
int sy, sx;
char arr[1001][1001];

int memo[1001][1001];
int dp() {
    int ret = -1;
    for (int x = sx; x < M; x++) {
        for (int y = 0; y < N; y++) {
            if (arr[y][x] == '#') continue;
            int &cur = memo[y][x];
            if (y > 0 && x > 0 && memo[y-1][x-1] != -1) cur = max(cur, memo[y-1][x-1]);
            if (x > 0 && memo[y][x - 1] != -1) cur = max(cur, memo[y][x - 1]);
            if (y < N - 1 && x > 0 && memo[y + 1][x-1] != -1) cur = max(cur, memo[y + 1][x-1]);
            if (memo[y][x] != -1) cur += arr[y][x] == 'C';
            if (arr[y][x] == 'O' && memo[y][x] != -1) {
                ret = max(ret, cur);
            }
        }
    }
    return ret;
}

void solve() {
    memset(memo, -1, sizeof(memo));
    scanf("%d %d", &N, &M);
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            scanf(" %c", &arr[y][x]);
            if (arr[y][x] == 'R') {
                sy = y, sx = x;
                memo[y][x] = 0;
            }
        }
    }
    printf("%d", dp());
}

int main() {
    solve();
}