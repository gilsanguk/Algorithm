#include <iostream>

using namespace std;

int N, K;

void solve() {
    scanf("%d", &N);
    int ans = 0;
    for (int i = 0; i < 5; i++) {
        scanf("%d", &K);
        ans += N == K;
    }
    printf("%d", ans);
}

int main() {
    solve();
}