// https://chanhuiseok.github.io/posts/algo-56/
#include <iostream>
#include <vector>
#define MAX 10001

using namespace std;

int N;
vector<int> graph[MAX];
int W[MAX];
int dp[MAX][2];
bool visited[MAX];

void dfs(int cur) {
    if (visited[cur]) return;
    visited[cur] = true;
    dp[cur][0] = 0;
    dp[cur][1] = W[cur];
    for (int& next: graph[cur]) {
        if (visited[next]) continue;
        dfs(next);
        dp[cur][0] += max(dp[next][0], dp[next][1]);
        dp[cur][1] += dp[next][0];
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &W[i]);
    }
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1);
    printf("%d", max(dp[1][0], dp[1][1]));
}