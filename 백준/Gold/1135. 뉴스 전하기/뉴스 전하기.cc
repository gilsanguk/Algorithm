#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> graph[51];

int dfs(int cur) {
    int ret = 0;
    vector<int> v;
    for (int& nxt : graph[cur]) {
        v.push_back(dfs(nxt));
    }
    sort(v.begin(), v.end(), greater<>());
    for (int i = 0; i < v.size(); i++) {
        ret = max(ret, v[i] + i + 1);
    }
    return ret;
}

void solve() {
    scanf("%d", &N);
    int a;
    scanf("%d", &a);
    for (int i = 1; i < N; i++) {
        scanf("%d", &a);
        graph[a].push_back(i);
    }
    printf("%d", dfs(0));
}

int main() {
    solve();
}