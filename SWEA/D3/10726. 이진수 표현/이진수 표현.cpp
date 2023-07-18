#include <iostream>

using namespace std;

int T, N, M;

void init() {
    scanf("%d %d", &N, &M);
}

void solve() {
    int cnt = 0;
    while (M) {
        if (M & 1) cnt++;
        else break;
        M >>= 1;
    }
    if (cnt >= N) printf("ON\n");
    else printf("OFF\n");
}

int main() {
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        printf("#%d ", i);
        init();
        solve();
    }
}