#include <iostream>
#include <queue>
#include <unordered_set>
#define ll long long

using namespace std;

int S, T;

void input() {
    scanf("%d %d", &S, &T);
}

struct Node {
    ll s;
    string op;
};
queue<Node> q;
unordered_set<ll> visited;
string bfs() {
    if (S == T) return "0";
    if (T == 0) return "-";
    q.push({S, ""});
    visited.insert(S);
    bool isFirst = true;
    while (!q.empty()) {
        ll s = q.front().s;
        string op = q.front().op;
        q.pop();
        if (s == T) return op;
        ll ns = s * s;
        if (ns <= T && visited.find(ns) == visited.end()) {
            visited.insert(ns);
            q.push({ns, op + "*"});
        }
        ns = s + s;
        if (ns <= T && visited.find(ns) == visited.end()) {
            visited.insert(ns);
            q.push({ns, op + "+"});
        }
        if (isFirst) {
            visited.insert(1);
            q.push({1, "/"});
            isFirst = false;
        }
    }
    return "-1";
}

void solve() {
    printf("%s", bfs().c_str());
}

int main() {
    input();
    solve();
}