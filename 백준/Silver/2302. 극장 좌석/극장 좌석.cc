#include <iostream>

using namespace std;

int N, M;

int memo[41];
int fibo(int n) {
    if (n < 2) return 1;
    if (memo[n]) return memo[n];
    return memo[n] = fibo(n - 1) + fibo(n - 2);
}

void solve() {
    scanf("%d %d", &N, &M);
    fibo(N);
    int ans = 1, prv = 1, cur;
    while (M--) {
        scanf("%d", &cur);
        ans *= fibo(cur - prv);
        prv = cur + 1;
    }
    ans *= fibo(N - prv + 1);
    printf("%d", ans);
}

int main() {
    solve();
}