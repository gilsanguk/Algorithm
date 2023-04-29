#include <iostream>
#include <string>

using namespace std;

int N;
int arr[21][21];
double dp[1 << 20];

double solve(int n, int visited) {
    if (n == N) return 1.0;
    double& ret = dp[visited];
    if (ret != -1) return ret;
    for (int i = 0; i < N; i++) {
        if (visited & (1 << i)) continue;
        ret = max(ret, solve(n + 1, visited | (1 << i)) * (double) (arr[n][i] / 100.0));
    }
    return ret;
}

int main() {
    for (int i = 0; i < 1 << 20; i++) {
        dp[i] = -1.0;
    }
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("%.6lf", solve(0, 0) * 100);
}