#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
vector<int> graph[201];
bool visited[201];
int prv, nxt;
bool ans = true;

bool dfs(int node) {
    if (node == nxt) return true;
    visited[node] = true;
    for (int next: graph[node]) {
        if (!visited[next]) {
            if (dfs(next)) return true;
        }
    }
    return false;
}

int main() {
    scanf("%d", &N);
    scanf("%d", &M);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int temp;
            scanf("%d", &temp);
            if (temp == 1) {
                graph[i].push_back(j);
            }
        }
    }
    scanf("%d", &prv);
    for (int i = 1; i < M; i++) {
        scanf("%d", &nxt);
        if (!dfs(prv)) {
            ans = false;
            break;
        }
        prv = nxt;
        memset(visited, false, sizeof(visited));
    }
    if (ans) printf("YES");
    else printf("NO");
}