#include <iostream>
#include <cstring>
#define MAX 1000001

using namespace std;

int N;
char txt[MAX];

void input() {
    scanf("%d", &N);
    scanf("%s", txt);
}

int f[MAX];
void getFail() {
    int j = 0;
    for (int i = 1; i < N; i++) {
        while (j > 0 && txt[i] != txt[j]) j = f[j - 1];
        if (txt[i] == txt[j]) f[i] = ++j;
    }
}

int memo[MAX];
int dp(int i) {
    if (i < 0 || f[i] == 0) return MAX;
    int& ret = memo[i];
    if (ret != -1) return ret;
    return ret = min(f[i], dp(f[i] - 1));
}

void solve() {
    memset(memo, -1, sizeof(memo));
    getFail();
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        int tmp = dp(i);
        if (tmp == MAX) continue;
        ans += i - tmp + 1;
    }
    printf("%lld", ans);
}

int main() {
    input();
    solve();
}