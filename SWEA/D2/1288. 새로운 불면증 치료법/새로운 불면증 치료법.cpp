#include <iostream>

using namespace std;

int T, N, M;
int check;

void init() {
    scanf("%d", &N);
    M = N;
    check = 0;
}

void solve() {
    while (check != (1 << 10) - 1) {
        int tmp = N;
        while (tmp) {
            check |= (1 << (tmp % 10));
            tmp /= 10;
        }
        N += M;
    }
    printf("%d\n", N - M);
}

int main() {
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        printf("#%d ", i);
        init();
        solve();
    }
}