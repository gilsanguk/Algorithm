#include <iostream>
#include <vector>

using namespace std;



struct Node {
    vector<int> children;
    int parents;
};

int T, V, E, S1, S2;
vector<Node> nodes;
vector<int> ancestorA, ancestorB;

void traverse(int idx, vector<int>& ancestor) {
    int parent = nodes[idx].parents;
    if (parent != 0) {
        traverse(parent, ancestor);
    }
    ancestor.push_back(idx);
}

int dfs(int idx) {
    if (nodes[idx].children.size() == 0) return 1;
    int res = 1;
    for (int child : nodes[idx].children) {
        res += dfs(child);
    }
    return res;
}

void input() {
    scanf("%d %d %d %d", &V, &E, &S1, &S2);
    nodes = vector<Node>(V + 1);
    ancestorA.clear();
    ancestorB.clear();
    for (int i = 0; i < E; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        nodes[a].children.push_back(b);
        nodes[b].parents = a;
    }
}

void solve() {
    input();
    traverse(S1, ancestorA);
    traverse(S2, ancestorB);
    int ans = 0;
    for (int i = 0; i < V; i++) {
        if (ancestorA[i] != ancestorB[i]) break;
        ans = ancestorA[i];
    }
    printf("%d %d\n", ans, dfs(ans));
}

int main() {
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        printf("#%d ", i);
        solve();
    }
}