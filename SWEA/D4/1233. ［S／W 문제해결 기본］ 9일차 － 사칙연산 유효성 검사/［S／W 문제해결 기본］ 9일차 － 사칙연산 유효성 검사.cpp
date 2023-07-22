#include <iostream>

using namespace std;

int N;
int idx, l, r;
char c;

int solve() {
    scanf("%d", &N);
    int ret = 1;
    for (int i = 0; i < N; i++) {
        scanf("%d %c", &idx, &c);
        if (idx <= N / 2) {
            if (idx == N / 2 && N % 2 == 0) {
                scanf("%d", &l);
            } else {
                scanf("%d %d", &l, &r);
            }
            if ('0' <= c && c <= '9') ret = 0;
        } else {
            if (!('0' <= c && c <= '9')) ret = 0;
        }
    }
    return ret;
}

int main() {
    for (int i = 1; i <= 10; i++) {
        printf("#%d ", i);
        printf("%d\n", solve());
    }
}