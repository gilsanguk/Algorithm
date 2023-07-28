#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001

#define ll long long

using namespace std;

int N;
double E;

struct Edge {
    int a, b;
    ll w;
    bool operator<(const Edge &e) const {
        return w < e.w;
    }
};
vector<Edge> edge;
ll X[MAX], Y[MAX];

void input() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%lld", &X[i]);
    }
    for (int i = 0; i < N; ++i) {
        scanf("%lld", &Y[i]);
    }
    scanf("%lf", &E);
}

ll getDist(int a, int b) {
    return (X[a] - X[b]) * (X[a] - X[b]) + (Y[a] - Y[b]) * (Y[a] - Y[b]);
}

void init() {
    edge.clear();
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            ll dist = getDist(i, j);
            edge.push_back({i, j, dist});
        }
    }
}

int parent[MAX];
int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return;
    parent[a] = b;
}

ll solve() {
    ll ans = 0;
    sort(edge.begin(), edge.end());
    for (int i = 0; i < N; ++i) {
        parent[i] = i;
    }
    for (auto [a, b, w] : edge) {
        if (find(a) == find(b)) continue;
        merge(a, b);
        ans += w;
    }
    return ans;
}

int T;
int main() {
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        input();
        init();
        printf("#%d %.lf\n", i, (double)solve() * E);
    }
}