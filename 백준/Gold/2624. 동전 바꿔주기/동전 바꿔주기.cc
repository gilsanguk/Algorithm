#include <iostream>
#include <string>

using namespace std;

int T, K;
int dp[10001];

int main() {
    scanf("%d\n%d", &T, &K);
    dp[0] = 1;
    for (int i = 0; i < K; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        for (int j = T; j >= 0; j--) {
            for (int k = 1; k <= b; k++) {
                if (k * a > j) break;
                dp[j] += dp[j - k * a];
            }
        }
    }
    printf("%d", dp[T]);
}