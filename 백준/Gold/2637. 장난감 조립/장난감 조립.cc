#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
struct Part {
    int idx, num;
};
vector<Part> graph[101];
int order[101], memo[101];

queue<int> q;
void bfs() {
    q.push(N);
    memo[N] = 1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (Part& p : graph[cur]) {
            memo[p.idx] += memo[cur] * p.num;
            if (--order[p.idx] != 0) continue;
            q.push(p.idx);
        }
    }
}

void solve() {
    scanf("%d %d", &N, &M);
    int X, Y, K;
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &X, &Y, &K);
        graph[X].push_back({Y, K});
        order[Y]++;
    }
    bfs();
    for (int i = 1; i < N; i++) {
        if (graph[i].empty()) {
            printf("%d %d\n", i, memo[i]);
        }
    }
}

int main() {
    solve();
}