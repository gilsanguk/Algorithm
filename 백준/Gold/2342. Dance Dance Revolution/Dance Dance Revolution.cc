#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
vector<int> V;
int dp[5][5][100002];

int dist(int a, int b) {
    if (a == 0) return 2;
    if (a == b) return 1;
    if (abs(a - b) == 3) return 3;
    return abs(a - b) + 2;
}

int solve(int cur, int l, int r){
    if(cur == N) return 0;
    int& ret = dp[l][r][cur];
    if(ret != -1) return ret;
    ret = min(
            solve(cur + 1, V[cur], r) + dist(l, V[cur]), solve(cur + 1, l, V[cur]) + dist(r, V[cur])
            );
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    memset(dp, -1, sizeof(dp));
    while(true) {
        int x;
        scanf("%d", &x);
        if(x == 0) break;
        V.push_back(x);
    }
    N = V.size();
    printf("%d", solve(0, 0, 0));
}