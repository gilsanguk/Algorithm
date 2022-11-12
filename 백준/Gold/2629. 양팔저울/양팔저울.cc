#include <iostream>
#include <cstring>
#define MAX 40000

using namespace std;

bool dp[31][80001];
int N, M, K;
int weight[31];

void solve(int n, int k) {
    if (n == N + 1 || dp[n][k]) return;
    dp[n][k] = true;
    solve(n + 1, k);
    solve(n + 1, k + weight[n]);
    solve(n + 1, k - weight[n]);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &weight[i]);
    }
    solve(0, MAX);
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &K);
        printf("%s ", dp[N][K+MAX] ? "Y": "N");
    }
}