#include <iostream>
#define ll long long

using namespace std;

int N;
ll arr[100001];

int solve(int s, int e) {
    if (s == e) return arr[s];
    int mid = (s + e) / 2;
    int lo = mid, hi = mid + 1;
    ll ret = max(solve(s, lo), solve(hi, e));
    ll height = min(arr[lo], arr[hi]);
    ret = max(ret, height * 2);
    while(s < lo || hi < e) {
        if (hi < e && (lo == s || arr[lo-1] < arr[hi + 1])){
            height = min(height, arr[++hi]);
        }
        else {
            height = min(height, arr[--lo]);
        }
        ret = max(ret, height * (hi - lo + 1));
    }
    return ret;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        scanf("%lld", &arr[i]);
    }
    printf("%d", solve(0, N-1));
}