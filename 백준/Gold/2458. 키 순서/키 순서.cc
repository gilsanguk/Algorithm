#include <iostream>
#define MAX 987654321

using namespace std;


int N, M;
int memo[501][501];

void F_W() {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                memo[i][j] = min(memo[i][j], memo[i][k] + memo[k][j]);
            }
        }
    }
}

void solve() {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            memo[i][j] = MAX;
    int a, b;
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &a, &b);
        memo[a][b] = 1;
    }
    F_W();
    int ans = 0;
    for (int i = 1; i <=N; i++) {
        int cnt = 0;
        for (int j = 1; j <=N; j++) {
            if (memo[i][j] != MAX || memo[j][i] != MAX) cnt++;
        }
        if (cnt == N - 1) ans++;
    }
    printf("%d", ans);
}

int main() {
    solve();
}