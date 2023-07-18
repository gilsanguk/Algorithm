#include <iostream>
#include <cstring>
#define ll long long
#define MAX 10001
#define MOD(x) ((x) % 1000000007)

using namespace std;

int T, N;
char str[MAX];

ll dp[MAX][1 << 4];
ll solve(int day, int key) {
    if (day == N) return 1;
    ll &ret = dp[day][key];
    if (ret != -1) return ret;
    ret = 0;
    int admin = 1 << (str[day] - 'A');
    for (int i = 1; i < 16; i++) {
        if ((admin & i) && ((i & key))) {
            ret = MOD(ret + solve(day + 1, i));
        }
    }
    return ret;
}

void init() {
    memset(dp, -1, sizeof(dp));
    memset(str, 0, sizeof(str));
    scanf("%s", str);
    N = strlen(str);
}


int main() {
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        printf("#%d ", i);
        init();
        printf("%lld\n", solve(0, 1));
    }
}