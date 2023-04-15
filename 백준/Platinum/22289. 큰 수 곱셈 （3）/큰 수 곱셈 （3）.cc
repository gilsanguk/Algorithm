#include <iostream>
#include <vector>
#include <complex>
#include <cstring>

using namespace std;

const double PI = acos(-1.0);
using cpx = complex<double>;

void fft(vector<cpx>& a, bool invert) {
    int N = a.size();
    for (int i = 1, j = 0; i < N; i++) {
        int bit = N >> 1;
        for (; j >= bit; bit >>= 1) {
            j -= bit;
        }
        j += bit;
        if (i < j) {
            swap(a[i], a[j]);
        }
    }
    for (int len = 2; len <= N; len <<= 1) {
        double angle = 2 * PI / len * (invert ? -1 : 1);
        cpx wlen(cos(angle), sin(angle));
        for (int i = 0; i < N; i += len) {
            cpx w(1);
            for (int j = 0; j < len / 2; j++) {
                cpx u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert) {
        for (int i = 0; i < N; i++) {
            a[i] /= N;
        }
    }
}

vector<int> multiply(vector<int>& a, vector<int>& b) {
    vector<cpx> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int N = 1;
    while (N < a.size() + b.size()) {
        N <<= 1;
    }
    fa.resize(N);
    fb.resize(N);
    vector<int> ret(N);
    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < N; i++) {
        fa[i] *= fb[i];
    }
    fft(fa, true);
    for (int i = 0; i < N; i++) {
        ret[i] = (int)(fa[i].real() + 0.5);
    }
    int carry = 0;
    for (int i = 0; i < N; i++) {
        ret[i] += carry;
        carry = ret[i] / 10;
        ret[i] %= 10;
    }
    return ret;
}

char str[2][1000001];
vector<int> a, b, ans;
int main() {
    scanf("%s %s", &str[0], &str[1]);
    int N = strlen(str[0]), M = strlen(str[1]);
    a.resize(N);
    b.resize(M);
    for (int i = 0; i < N; i++) {
        a[i] = str[0][N - i - 1] - '0';
    }
    for (int i = 0; i < M; i++) {
        b[i] = str[1][M - i - 1] - '0';
    }
    ans = multiply(a, b);
    while (ans.size() > 1 && ans.back() == 0) {
        ans.pop_back();
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        printf("%d", ans[i]);
    }
}
