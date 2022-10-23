#include <iostream>
#include <vector>
#include <cstring>
#define x first
#define y second
#define ll long long

using namespace std;
pair<ll,ll> A, B, C, D;
int ccw(pair<ll,ll> a, pair<ll,ll> b, pair<ll,ll> c){
    ll ret = a.x*b.y + b.x*c.y + c.x*a.y;
    ret -= (a.y*b.x + b.y*c.x + c.y*a.x);
    if (ret > 0) return 1;
    if (ret == 0) return 0;
    return -1;
}

int solve(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c, pair<ll, ll> d){
    int ab = ccw(a, b, c) * ccw(a, b, d);
    int cd = ccw(c, d, a) * ccw(c, d, b);
    if (ab == 0 && cd == 0) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        return c <= b && a <= d;
    }
    return ab <= 0 && cd <= 0;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for (int i = 0; i < 2; i++) {
        cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
    }
    cout << solve(A, B, C, D) << '\n';
}