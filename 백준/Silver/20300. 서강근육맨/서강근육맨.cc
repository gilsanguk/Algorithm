#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

int N;
ll arr[10001];

void input() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%lld", &arr[i]);
}

void solve() {
    sort(arr, arr + N);
    int l = 0, r = N - 1 - (N & 1);
    ll ans = arr[N - 1];
    while (l < r)
        ans = max(ans, arr[l++] + arr[r--]);
    printf("%lld", ans);
}

int main() {
    input();
    solve();
}