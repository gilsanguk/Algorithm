#include <iostream>
#include <cstring>

using namespace std;

int N, M;
int arr[21];

void input() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &M);
}

int memo[10001][21];
int dp(int cost, int idx) {
    if (cost == M) return 1;
    if (idx == N) return 0;
    int& ret = memo[cost][idx];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 0; cost + arr[idx] * i <= M; i++)
        ret += dp(cost + arr[idx] * i, idx + 1);
    return ret;
}

void solve() {
    memset(memo, -1, sizeof(memo));
    printf("%d\n", dp(0, 0));
}

int T;
int main() {
    scanf("%d", &T);
    while (T--) {
        input();
        solve();
    }
}