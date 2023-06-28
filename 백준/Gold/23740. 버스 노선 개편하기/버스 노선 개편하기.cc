#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
struct Node {
    int s, e, c;
    bool operator<(const Node& rhs) const {
        if (s == rhs.s) return e > rhs.e;
        return s < rhs.s;
    }
};
vector<Node> route;

void solve() {
    scanf("%d", &N);
    route.resize(N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &route[i].s, &route[i].e, &route[i].c);
    }
    sort(route.begin(), route.end());
    vector<Node> ans;
    ans.push_back(route[0]);
    for (int i = 1; i < N; i++) {
        if (ans.back().e < route[i].s) {
            ans.push_back(route[i]);
            continue;
        }
        ans.back().s = min(ans.back().s, route[i].s);
        ans.back().e = max(ans.back().e, route[i].e);
        ans.back().c = min(ans.back().c, route[i].c);
    }
    printf("%d\n", ans.size());
    for (Node& n : ans) {
        printf("%d %d %d\n", n.s, n.e, n.c);
    }
}

int main() {
    solve();
}