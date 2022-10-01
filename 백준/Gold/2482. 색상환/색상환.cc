#include <iostream>
#include <string.h>
#define MOD 1000000003
using namespace std;
int dp[1001][1001];

int dynamic(int n, int k){
    int& ret = dp[n][k];
    if (2*k - 1 > n) return 0;
    if (k == 0) return 1;
    if (2*k - 1 == n) return 1;
    if (ret != -1) return ret;
    ret = dynamic(n - 1, k) + dynamic(n - 2, k - 1);
    ret = ret % MOD;
    return ret;
}

int main(){
    int N, K;
    cin >> N >> K;
    memset(dp, -1, sizeof(dp));
    cout << (dynamic(N - 3, K - 1) + dynamic(N - 1, K)) % MOD;
}