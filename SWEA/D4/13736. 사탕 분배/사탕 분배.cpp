#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

int A, B, K;

void input() {
    scanf("%d %d %d", &A, &B, &K);
}

ll solve() {
    int sum = A + B;
    int max = sum / 2;
    ll res = 1, num = 2;
    while (K) {
        if (K & 1) res = (res * num) % sum;
        num = (num * num) % sum;
        K >>= 1;
    }
    res = (res * A) % sum;
    return res > max ? sum - res : res;
}

int T;
int main() {
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        input();
        printf("#%d ", i);
        printf("%lld\n", solve());
    }
}