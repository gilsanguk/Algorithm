#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
vector<int> graph[1001];

void input() {
    int cnt, n;
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &cnt);
        for (int j = 0; j < cnt; j++) {
            scanf("%d", &n);
            graph[i].push_back(n);
        }
    }
}

int matched[1001];
bool visited[1001];
int dfs(int x) {
    for (int nx: graph[x]) {
        if (visited[nx]) continue;
        visited[nx] = true;
        if (!matched[nx] || dfs(matched[nx])) {
            matched[nx] = x;
            return 1;
        }
    }
    return 0;
}

void solve() {
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        memset(visited, false, sizeof(visited));
        ans += dfs(i);
    }
    printf("%d", ans);
}

int main() {
    input();
    solve();
}