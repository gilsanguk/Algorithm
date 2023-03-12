// cf.https://ohgym.tistory.com/19
#include <iostream>
#define MAX 42000
#define ll long long

ll K;
ll arr[MAX];

void mobius() {
    arr[1] = 1;
    for (ll i = 1; i < MAX; i++) {
        for (ll j = i * 2; j < MAX; j += i) {
            arr[j] -= arr[i];
        }
    }
}

ll query(ll m) {
    ll ret = 0;
    for (ll i = 1; i * i <= m; i++) {
        ret += arr[i] * m / (i * i);
    }
    return ret;
}

ll find(ll s, ll e) {
    while (s < e - 1) {
        ll m = (s + e) >> 1;
        if (query(m) < K) s = m;
        else e = m;
    }
    return e;
}

int main() {
    scanf("%lld", &K);
    mobius();
    printf("%lld", find(0, K*2));
}