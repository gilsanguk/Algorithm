#include <iostream>
#include <set>

using namespace std;

int A, B, C;
set<int> ans;

bool visited[201][201][201];
void dfs(int a, int b, int c) {
    if (visited[a][b][c]) return;
    visited[a][b][c] = true;
    if (a == 0) ans.insert(c);

    int a2b = min(a, B - b);
    if (a2b) dfs(a - a2b, b + a2b, c);

    int a2c = min(a, C - c);
    if (a2c) dfs(a - a2c, b, c + a2c);

    int b2a = min(b, A - a);
    if (b2a) dfs(a + b2a, b - b2a, c);

    int b2c = min(b, C - c);
    if (b2c) dfs(a, b - b2c, c + b2c);

    int c2a = min(c, A - a);
    if (c2a) dfs(a + c2a, b, c - c2a);

    int c2b = min(c, B - b);
    if (c2b) dfs(a, b + c2b, c - c2b);
}

void solve() {
    scanf("%d %d %d", &A, &B, &C);
    dfs(0, 0, C);
    for (int an : ans) {
        printf("%d ", an);
    }
}

int main() {
    solve();
}