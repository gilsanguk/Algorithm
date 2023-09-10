#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int arr[10001];
vector<int> graph[10001];

void input() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &arr[i]);
    int s, e;
    for (int i = 1; i < N; i++) {
        scanf("%d %d", &s, &e);
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
}

// 그래프를 임의의 정점(1)을 root로 하는 트리로 변환
vector<int> tree[10001];
void dfs(int cur, int prv) {
    for (int& nxt : graph[cur]) {
        if (nxt != prv) {
            tree[cur].push_back(nxt);
            dfs(nxt, cur);
        }
    }
}

int memo[10001][2];
int dp(int cur, int flag) {
    int& ret = memo[cur][flag];
    if (flag) {
        ret = arr[cur];
        for (int& nxt : tree[cur])
            ret += dp(nxt, 0);
    }
    else {
        ret = 0;
        for (int& nxt : tree[cur])
            ret += max(dp(nxt, 0), dp(nxt, 1));

    }
    return ret;
}

vector<int> ans;
bool visited[10001];
void track(int cur, int prv) {
    if (memo[cur][1] > memo[cur][0] && !visited[prv]) {
        ans.push_back(cur);
        visited[cur] = true;
    }
    for (int& nxt : tree[cur])
        track(nxt, cur);
}

void solve() {
    memset(memo, -1, sizeof(memo));
    dfs(1, -1);
    printf("%d\n", max( dp(1, 0), dp(1, 1)));
    track(1, 1);
    sort(ans.begin(), ans.end());
    for (int& i : ans)
        printf("%d ", i);
}

int main() {
    input();
    solve();
}