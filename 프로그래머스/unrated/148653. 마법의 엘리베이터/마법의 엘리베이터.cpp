#include <algorithm>
#include <cstring>

using namespace std;

int dp[10];

int solve(int depth, int base, int num) {
    if (depth == 9 || num == 0) return 0;
    int& ret = dp[depth];
    // if(ret != -1) return ret;
    int base_ten = base*10;
    int cur = num%base_ten;
    if (cur == 0) return solve(depth + 1, base * 10, num);
    ret = min(
        solve(depth + 1, base *10, num - cur) + cur/base, 
        solve(depth + 1, base*10, num + base_ten - cur) + (base_ten - cur)/base
    );
    return ret;
}

int solution(int storey) {
    memset(dp, -1, sizeof(dp));
    return solve(0, 1, storey);
}