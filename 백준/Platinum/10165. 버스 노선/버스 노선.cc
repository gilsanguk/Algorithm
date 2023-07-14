#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
struct Edge {
    int n, s, e;
    bool operator<(const Edge& rhs) const {
        if (s == rhs.s) return e > rhs.e;
        return s < rhs.s;
    }
};
vector<Edge> graph;

void solve() {
    scanf("%d %d", &N, &M);
    graph.resize(M);
    int reverseMax = 0;
    for (int i = 0; i < M; i++) {
        graph[i].n = i + 1;
        scanf("%d %d", &graph[i].s, &graph[i].e);
        if (graph[i].s > graph[i].e) {
            reverseMax = max(reverseMax, graph[i].e);
            graph[i].e += N;
        }
    }
    sort(graph.begin(), graph.end());
    vector<Edge> ans;
    vector<int> v;
    for (Edge cur : graph) {
        if (cur.e <= reverseMax) continue;
        if (ans.empty() || ans.back().e < cur.e) {
            ans.push_back(cur);
            v.push_back(cur.n);
        }
    }
    sort(v.begin(), v.end());
    for (int& i : v) printf("%d ", i);
}

int main() {
    solve();
}