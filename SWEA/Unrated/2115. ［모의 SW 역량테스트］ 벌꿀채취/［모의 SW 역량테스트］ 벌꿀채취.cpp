#include <iostream>
#include <algorithm>
#include <vector>
#include<cstring>
using namespace std;
int T, N, M, C;
int map[11][11];

int backtrack(vector<vector<int>> & honey){
    int ret = 0;
    for(int i = 0; i < honey.size() - 1; i++){
        for(int j = i+1; j < honey.size(); j++){
            if (honey[i][0] == honey[j][0] && honey[i][1] + M > honey[j][1]) continue;
            ret = max(ret, honey[i][2] + honey[j][2]);
        }
    }
    return ret;
}

int solve(int y, int x){
    int dp[11][31];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < M; i++){
        for(int j = 0; j <= C; j++){
            if (map[y][x+i] > j){
                dp[i+1][j] = dp[i][j];
            }
            else{
                dp[i+1][j] = max(dp[i][j], dp[i][j-map[y][x+i]] + map[y][x+i]*map[y][x+i]);
            }
        }
    }
    return dp[M][C];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; t++){
        cin >> N >> M >> C;
        for (int y = 0; y < N; y++){
            for (int x = 0; x < N; x++){
                cin >> map[y][x];
            }
        }
        vector<vector<int>> honey;
        for (int y = 0; y < N; y++){
            for (int x = 0; x <= N - M; x++){
                honey.push_back({y, x, solve(y, x)});
            }
        }
        cout << "#" << t+1 << " " << backtrack(honey) << endl;
    }
}