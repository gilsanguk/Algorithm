#include <iostream>
#include <vector>
#define MAX 1000001

using namespace std;

int N;
char txt[MAX * 2];
char pat[MAX];

void input() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf(" %c", &txt[i]);
    for (int i = 0; i < N - 1; i++)
        txt[N + i] = txt[i];
    for (int i = 0; i < N; i++)
        scanf(" %c", &pat[i]);
}

vector<int> getFail() {
    vector<int> f(N);
    int j = 0;
    for (int i = 1; i < N; i++) {
        while (j > 0 && pat[i] != pat[j]) j = f[j - 1];
        if (pat[i] == pat[j]) f[i] = ++j;
    }
    return f;
}

int kmp() {
    vector<int> fail = getFail();
    int j = 0, cnt = 0;
    for (int i = 0; i < N * 2 - 1; i++) {
        while (j > 0 && txt[i] != pat[j]) j = fail[j - 1];
        if (txt[i] == pat[j]) j++;
        if (j == N) {
            cnt++;
            j = fail[j - 1];
        }
    }
    return cnt;
}

int gcd(int a, int b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

void solve() {
    int ans = kmp();
    int g = gcd(N, ans);
    printf("%d/%d", ans / g, N / g);
}

int main() {
    input();
    solve();
}