#include <iostream>
#include <cstring>
#define ll long long
#define MOD(x) ((x) % 1000000007)

using namespace std;

int N;

void input() {
    scanf("%d", &N);
}

ll memo[1516][3];
ll ezreal(int n, int m) {
    if (n == 1) return m == 2;
    ll& ret = memo[n][m];
    if (ret != -1) return ret;
    ret = MOD(ezreal(n - 1, (m + 1) % 3) + ezreal(n - 1, (m + 5) % 3));
    return ret;
}

void solve() {
    memset(memo, -1, sizeof(memo));
    printf("%lld", ezreal(N, 0));
}

int main() {
    input();
    solve();
}