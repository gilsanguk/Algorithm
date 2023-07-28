#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 100001
#define ll long long

using namespace std;

int N;
vector<int> graph[MAX];
int par[MAX][20];
int d[MAX];
bool visit[MAX];

void init() {
    for (int i = 0; i < MAX; i++) {
        graph[i].clear();
    }
    memset(d, 0, sizeof(d));
    memset(visit, false, sizeof(visit));
}

int LCA(int x, int y, int cnt) {
    if (d[x] > d[y])
        swap(x, y);
    if (par[y][0] == x) {
        return 1;
    }
    for (int i = 19; i >= 0; i--) {
        if (d[y] - d[x] >= (1 << i)) {
            y = par[y][i];
            cnt += (1 << i);
        }
    }
    if (par[y][0] != par[x][0]) {
        for (int i = 19; i >= 0; i--) {
            if (par[x][i] != par[y][i]) {
                cnt += 2 * (1 << i);
                x = par[x][i];
                y = par[y][i];
            }
        }
    }
    if (par[x][0] == par[y][0]) {
        return cnt + 2;
    }
}

ll int bfs() {
    long long int result = 0;
    int pre, cur;
    queue<int> q;
    q.push(1);
    visit[1] = true;
    pre = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < graph[x].size(); i++) {
            int y = graph[x][i];
            if (visit[y])
                continue;
            q.push(y);
            cur = y;
            visit[y] = true;
            result += LCA(pre, cur, 0);
            pre = cur;
        }
    }
    return result;
}

void input() {
    scanf("%d", &N);
    int k;
    par[1][0] = 0;
    d[1] = 0;
    for (int i = 2; i <= N; i++) {
        scanf("%d", &k);
        graph[k].push_back(i);
        par[i][0] = k;
        d[i] = d[k] + 1;
    }
    for (int y = 1; y < 20; y++) {
        for (int x = 1; x <= N; x++) {
            par[x][y] = par[par[x][y - 1]][y - 1];
        }
    }
}

int T;
int main() {
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        init();
        input();
        printf("#%d %lld\n", i, bfs());
    }
    return 0;
}