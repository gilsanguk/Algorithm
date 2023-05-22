#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> adj[1000001];
int dp[1000001][2];
bool visited[1000001];

void solve(int x) {
    visited[x] = true;
    dp[x][0] = 1;
    for (int &nxt: adj[x]) {
        if (visited[nxt]) continue;
        solve(nxt);
        dp[x][1] += dp[nxt][0];
        dp[x][0] += min(dp[nxt][1], dp[nxt][0]);
    }
}

int main() {
    scanf("%d", &N);
    int s, e;
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &s, &e);
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    solve(1);
    printf("%d", min(dp[1][0], dp[1][1]));
}