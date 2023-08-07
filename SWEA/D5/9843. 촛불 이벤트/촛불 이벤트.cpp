#include <iostream>
#include <algorithm>
#include <cmath>
#define ll long long

using namespace std;

ll N;

void input() {
    scanf("%lld", &N);
}

ll solve() {
    ll l = 1, r = sqrt(N * 2);
    ll ans = 0;
    while (l <= r) {
        ll mid = (l + r) / 2;
        ll sum = mid / 2 * (mid + 1);
        if (sum <= N) {
            ans = max(ans, mid);
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    ll v = ans * (ans + 1) / 2;
    if (v != N) return -1;
    return ans;
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