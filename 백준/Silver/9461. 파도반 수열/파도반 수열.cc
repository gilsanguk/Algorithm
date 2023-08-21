#include <iostream>
#include <cstring>
#define ll long long

using namespace std;

int T, N;

ll memo[101];
ll solve(int n) {
    if (n < 4) return 1;
    if (memo[n] != -1) return memo[n];
    return memo[n] = solve(n - 2) + solve(n - 3);
}

int main() {
    memset(memo, -1, sizeof(memo));
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d", &N);
        printf("%lld\n", solve(N));
    }
}