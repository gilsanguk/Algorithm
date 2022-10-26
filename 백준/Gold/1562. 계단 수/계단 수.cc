#include <iostream>
#include <cstring>
#define MOD(x) (x) % 1000000000

using namespace std;

int N;
int memo[101][10][1 << 10];

int dp(int idx, int num, int used) {
    if (idx == N) return used == (1 << 10) - 1 ? 1 : 0;
    int &ret = memo[idx][num][used];
    if (ret != -1) return ret;
    ret = 0;
    if (num < 9) ret += dp(idx+1, num+1, used|(1<<(num+1)));
    if (num > 0) ret += dp(idx+1, num-1, used|(1<<(num-1)));
    ret = MOD(ret);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    memset(memo, -1, sizeof(memo));
    cin >> N;
    int ans = 0;
    for (int i = 1; i < 10; i++) {
        ans = MOD(ans + dp(1, i, 1 << i));
    }
    cout << ans;
}