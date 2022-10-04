#include <string>
#include <vector>

using namespace std;
#define INF 20000000
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
   int answer = INF;
   vector <vector<int>> dp(n + 1, vector<int>(n + 1, INF));
   for (int i = 1; i < n + 1; i++) dp[i][i] = 0;
    
   for (int i = 0; i < fares.size(); i++){
       dp[fares[i][0]][fares[i][1]] = fares[i][2];
       dp[fares[i][1]][fares[i][0]] = fares[i][2];
   }
    
   for (int k = 1; k < n + 1; k++){
       for (int i = 1; i < n + 1; i++){
           for (int j = 1; j < n + 1; j++){
               if (dp[i][j] > dp[i][k] + dp[k][j]) {
                   dp[i][j] = dp[i][k] + dp[k][j];
               }
           }
       }
   }
    
    for (int k = 1; k < n + 1; k++){
        answer = min(answer, dp[s][k] + dp[k][a] + dp[k][b]);
    }
    return answer;
}