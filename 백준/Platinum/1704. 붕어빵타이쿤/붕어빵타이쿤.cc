#include <iostream>
#include <cstring>
using namespace std;

int N, M;
int arr[16][16];
int dy[5] = { 0, 0, 1, -1, 0 };
int dx[5] = { 1, -1, 0, 0, 0 };
int cnt = 987654321;
int ans[16][16];
int tmp[16][16];
int revCnt;

void reverse(int fishBread[][16], int y, int x) {
    for (int i = 0; i < 5; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        fishBread[ny][nx] ^= 1;
    }
}

void solve(int cur[][16], int n) {
    if (n == N) {
        int sum = 0;
        for (int i = 0; i < M; i++) {
            sum += cur[N-1][i];
        }
        if (sum == 0) {
            if (cnt > revCnt) {
                cnt = revCnt;
                memcpy(ans, tmp, sizeof(tmp));
            }
            if (cnt == revCnt) {
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < M; j++) {
                        if (ans[i][j] > tmp[i][j]) {
                            memcpy(ans, tmp, sizeof(tmp));
                            return;
                        }
                        else if (ans[i][j] < tmp[i][j]) {
                            return;
                        }
                    }
                }
            }
        }
        return;
    }

    for (int i = 0; i < M; i++) {
        if (cur[n-1][i] == 1) {
            reverse(cur, n, i);
            revCnt++;
            tmp[n][i] = 1;
        }
    }
    solve(cur, n + 1);
}

int main() {
    scanf("%d %d", &N, &M);
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            scanf("%d", &arr[y][x]);
        }
    }
    int max = 1 << M;
    for (int i = 0; i < max; i++) {
        int cur[16][16];
        revCnt = 0;
        memcpy(cur, arr, sizeof(arr));
        memset(tmp, 0, sizeof(tmp));
        for (int j = 0; j < M; j++) {
            if (i & (1 << j)) {
                reverse(cur, 0, j);
                tmp[0][j] = 1;
                revCnt++;
            }
        }
        solve(cur, 1);
    }
    if (cnt == 987654321) {
        printf("IMPOSSIBLE");
    }
    else {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                printf("%d ", ans[i][j]);
            }
            printf("\n");
        }
    }
}
