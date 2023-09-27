#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

int N;
vector<ll> v;

void backtrack(ll n, int l) {
    if (l == 10) return;
    v.push_back(n);
    for (int i = 0; i < n % 10; i++)
        backtrack(n * 10 + i, l + 1);
}

ll solve() {
    if (N > 1023) return -1;
    for (int i = 0 ; i < 10; i++)
        backtrack(i, 0);
    sort(v.begin(), v.end());
    return v[N - 1];
}

int main() {
    scanf("%d", &N);
    printf("%lld", solve());
}