#include <iostream>
#include <vector>
#include <cstring>
#define ll long long
#define MAX 100001

using namespace std;

int N;
vector<int> graph[MAX];

void input() {
    scanf("%d", &N);
    int s, e;
    for (int i = 1; i < N; i++) {
        scanf("%d %d", &s, &e);
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
}

vector<int> tree[MAX];
void dfs(int cur, int prv) {
    for (int& nxt : graph[cur]) {
        if (nxt != prv) {
            tree[cur].push_back(nxt);
            dfs(nxt, cur);
        }
    }
}

ll memo[MAX][15];
ll dp(int cur, int prv) {
    ll& ret = memo[cur][prv];
    if (ret != -1) return ret;
    ret = prv;
    for (int& nxt : tree[cur]) {
        ll tmp = 1e18;
        for (int i = 1; i < 15; i++) {
            if (prv == i) continue;
            tmp = min(tmp, dp(nxt, i));
        }
        ret += tmp;
    }
    return ret;
}

void solve() {
    memset(memo, -1, sizeof(memo));
    dfs(1, -1);
    ll ans = 1e18;
    for (int i = 1; i < 15; i++)
        ans = min(ans, dp(1, i));
    printf("%lld", ans);
}

int main() {
    input();
    solve();
}