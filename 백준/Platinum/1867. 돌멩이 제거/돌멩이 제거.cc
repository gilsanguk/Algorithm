#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, K;
int matched[501];
bool visited[501];
vector<int> row[501];

bool dfs(int y) {
    if (visited[y]) return false;
    visited[y] = true;
    for (int& nxt : row[y]) {
        if (matched[nxt] == 0 || dfs(matched[nxt])) {
            matched[nxt] = y;
            return true;
        }
    }
    return false;
}

void solve() {
    scanf("%d %d", &N, &K);
    int y, x;
    for (int i = 0; i < K; i++) {
        scanf("%d %d", &x, &y);
        row[y].push_back(x);
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        memset(visited, false, sizeof(visited));
        ans += dfs(i);
    }
    printf("%d", ans);
}

int main() {
    solve();
}