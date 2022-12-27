#include <iostream>
#include <map>
#include <vector>

using namespace std;

int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int N, M, K;
int y, x, m, s, d;
map<pair<int, int>, vector<vector<int>>> pre;

void go(int& ny, int& nx){
    if (ny > N) ny %= N;
    if (ny < 1) ny = N + ny % N;
    if (nx > N) nx %= N;
    if (nx < 1) nx = N + nx % N;
}

void solve() {
    map<pair<int, int>, vector<vector<int>>> nxt;
    for (const auto &[k, V]: pre) {
        y = k.first, x = k.second;
        for (const auto &v : V){
            m = v[0], s = v[1], d = v[2];
            int ny = y + dy[d] * s, nx = x + dx[d] * s;
            go(ny, nx);
            nxt[{ny, nx}].push_back({m, s, d});
        }
    }
    pre.clear();
    for (auto const &[k, V]: nxt) {
        y = k.first, x = k.second;
        if (V.size() > 1) {
            int ns = 0, nm = 0, nd = V[0][2] & 1;
            bool flag = true;
            for (const auto &v : V){
                m = v[0], s = v[1], d = v[2];
                ns += s, nm += m;
                if (nd != (d & 1)) flag = false;
            }
            nm /= 5;
            if (nm == 0) continue;
            ns /= V.size();
            nd = flag ? 0 : 1;
            for (int i = nd; i < 8; i+=2){
                pre[{y, x}].push_back({nm, ns, i});
            }
        }
        else {
            if (V[0][0] == 0) continue;
            pre[{y, x}].push_back({V[0][0], V[0][1], V[0][2]});
        }
    }
}

int main() {
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d %d %d", &y, &x, &m, &s, &d);
        pre[{y, x}].push_back({m, s, d});
    }
    for (int i = 0; i < K; i++){
        solve();
    }
    int ans = 0;
    for (auto const &[k, V]: pre) {
        for (const auto &v : V){
            ans += v[0];
        }
    }
    printf("%d", ans);
}