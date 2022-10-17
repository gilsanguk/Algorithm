#include <iostream>
#include <cstring>

using namespace std;

int C, D, M;
int stock[50][15];
int dp[500001];

int main(){
    cin >> C >> D >> M;
    for (int i = 0; i < C; i ++){
        for (int j = 0; j < D; j++){
            cin >> stock[i][j];
        }
    }
    int money = M;
    for (int j = 1; j < D; j++){
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < C; i++) {
            for (int k = stock[i][j-1]; k <= money; k++){
                dp[k] = max(dp[k], dp[k - stock[i][j-1]] + stock[i][j] - stock[i][j-1]);
            }
        }
        money += dp[money];
    }
    cout << money << '\n';
}