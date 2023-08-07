#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

int N;
ll M;
ll arr[101];
ll maxV;

void input() {
    scanf("%d %lld", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &arr[i]);
        maxV = max(maxV, arr[i]);
    }
}

ll solve() {
    ll ans = 0;
    ll l = 1, r = maxV;
    while (l <= r) {
        ll mid = (l + r) / 2;
        ll sum = 0;
        for (int i = 0; i < N; i++) {
            sum += arr[i] / mid;
        }
        if (sum >= M) {
            l = mid + 1;
            ans = max(ans, mid);
        } else {
            r = mid - 1;
        }
    }
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