#include <iostream>
#include <vector>
#define ll long long
#define MAX 123457

using namespace std;

int N;
int node[MAX];
vector<int> graph[MAX];

ll dfs(int cur) {
    ll ret = 0;
    for (int next : graph[cur]) {
        ret += dfs(next);
    }
    return max(0LL, ret + node[cur]);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &N);
    for (int i = 2; i <= N; i++) {
        char c;
        int val, next;
        scanf(" %c %d %d", &c, &val, &next);
        node[i] = c == 'S' ? val : -val;
        graph[next].push_back(i);
    }
    printf("%lld", dfs(1));
}