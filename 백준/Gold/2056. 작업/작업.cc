#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int t[10001];
vector<int> graph[10001];
int order[10001];
int memo[10001];

int ans;
queue<int> q;
void tpSort() {
    for (int i = 1; i <= N; i++) {
        if (order[i] == 0) q.push(i);
        memo[i] = t[i];
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        ans = max(ans, memo[cur]);
        for (int& nxt : graph[cur]) {
            memo[nxt] = max(memo[nxt], memo[cur] + t[nxt]);
            if (--order[nxt] == 0) q.push(nxt);
        }
    }
}

void solve() {
    scanf("%d", &N);
    int prev;
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &t[i], &order[i]);
        for (int j = 0; j < order[i]; j++) {
            scanf("%d", &prev);
            graph[prev].push_back(i);
        }
    }
    tpSort();
    printf("%d", ans);
}

int main() {
    solve();
}