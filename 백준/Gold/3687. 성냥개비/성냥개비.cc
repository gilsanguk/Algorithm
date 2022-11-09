#include <iostream>
#include <algorithm>
#define MAX 999999999999999
#define TEST

using namespace std;
using ll = long long;

int T, N;
ll arr[9] = {0, 0, 1, 7, 4, 2, 0, 8, 10};
ll dp[101] = {0, 0, 1, 7, 4, 2, 6, 8, 10, };
void solve(){
    for (int i = 9; i <= 100; i++){
        dp[i] = MAX;
        for (int j = 2; j < 8; j++){
            dp[i] = min(dp[i], dp[i - j]*10 + arr[j]);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &T);
    solve();
    while(T--){
        scanf("%d", &N);
        printf("%lld ", dp[N]);
        if (N & 1){
            printf("7");
            N -= 3;
        }
        for (int i = 0; i < (N >> 1); i++){
            printf("1");
        }
        printf("\n");
    }
}