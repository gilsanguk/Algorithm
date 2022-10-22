#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, W, V;
priority_queue<pair<int,int>> pq;
priority_queue<int> possible;

int solve(){
    int ret = 0;
    for (int i = N; i > 0; i--) {
        while (!pq.empty() && pq.top().first >= i) {
            possible.push(pq.top().second);
            pq.pop();
        }
        if (!possible.empty()) {
            ret += possible.top();
            possible.pop();
        }
    }
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> V >> W;
        pq.push({W, V});
    }
    cout << solve() << '\n';
}