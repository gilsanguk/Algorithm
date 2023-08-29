// https://jaeseo0519.tistory.com/122
// so hard ...
#include <iostream>
#include <complex>
#include <vector>
#include <cmath>
#define ll long long

using namespace std;

typedef complex<double> base;
const double PI = acos(-1);

int N;
vector<ll> A, B, C;
void input() {
    scanf("%d", &N);
    A.resize(N * 2);
    B.resize(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
        A[N + i] = A[i];
    }
    for (int i = 1; i <= N; i++)
        scanf("%lld", &B[N - i]);
}

void fft(vector<base>& a, bool invert) {
    int n = (int) a.size();
    for (int i = 1, j = 0; i < n; i++) { // sorting
        int bit = n >> 1;
        while (!((j ^= bit) & bit)) bit >>= 1; // odd, even
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        double theta = 2 * PI / len * (invert ? -1 : 1); // e^(2*PI*i/len)
        base wLen(cos(theta), sin(theta)); // e^(theta) = cos(theta) + i*sin(theta)
        for (int i = 0; i < n; i += len) {
            base w(1);
            for (int j = 0; j < len / 2; j++) {
                base u = a[i + j], v = a[i + j + len / 2] * w; // G(u), w*H(v)
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wLen; // rotate
            }
        }
    }
    if (invert) for (int i = 0; i < n; i++) a[i] /= n;
}

vector<ll> multiply(vector<ll>& a, vector<ll>& b) {
    vector<base> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;
    fa.resize(n); fb.resize(n);
    fft(fa, false); fft(fb, false); // transform
    for (int i = 0; i < n; i++) fa[i] *= fb[i];
    fft(fa, true); // inverse transform
    vector<ll> ret(n);
    for (int i = 0; i < n; i++) ret[i] = (ll)round(fa[i].real());
    return ret;
}

void solve() {
    C = multiply(A, B);
    ll ans = 0;
    for (ll c : C) ans = max(ans, c);
    printf("%lld", ans);
}

int main() {
    input();
    solve();
}