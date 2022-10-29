#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long

using namespace std;
int N;
vector<ll> H;

ll solve(int s, int e){
    if (s == e) return H[s];
    int mid = (s + e) / 2;
    int lo = mid, hi = mid + 1;
    ll ret = max(solve(s, lo), solve(hi, e));
    ll height = min(H[lo], H[hi]);
    ret = max(ret, height * 2);
    while(s < lo || hi < e){
        if (hi < e && (lo == s || H[lo-1] < H[hi + 1])) height = min(height, H[++hi]);
        else height = min(height, H[--lo]);
        ret = max(ret, height * (hi - lo + 1));
    }
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    while(true){
        cin >> N;
        if (N == 0) break;
        H.clear();
        H.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> H[i];
        }
        cout << solve(0, N - 1) << '\n';
    }
}