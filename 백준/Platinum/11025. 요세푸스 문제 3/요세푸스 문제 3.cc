#include <iostream>

using namespace std;

int N, K;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d", &N, &K);
    int ans = 1;
    for (int i = 2; i <= N; i++){
        ans = (ans + K - 1) % i + 1;
    }
    printf("%d", ans);
}