#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

char t1[41];
char t2[41];
int N, M;
int memo[41][41];

int dp(int n, int m) {
    int &ret = memo[n][m];
    if (n == N || m == M) return ret = 0;
    if (ret != -1) return ret;
    ret = max(dp(n, m + 1), dp(n + 1, m));
    if (t1[n] == t2[m]) {
        ret = max(ret, dp(n + 1, m + 1) + 1);
    }
    return ret;
}

void solve() {
    scanf("%s", t1);
    scanf("%s", t2);
    N = strlen(t1);
    M = strlen(t2);
    memset(memo, -1, sizeof(memo));
    dp(0, 0);
    int y = 0, x = 0;
    string ans;
    while (memo[y][x]) {
        if (memo[y][x] == memo[y + 1][x]) {
            y++;
        }
        else if (memo[y][x] == memo[y][x + 1]) {
            x++;
        }
        else {
            ans += t1[y];
            y++;
            x++;
        }
    }
    printf("%s", ans.c_str());
}

int main() {
    solve();
}