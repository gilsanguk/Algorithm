#include <iostream>
#include <queue>

using namespace std;

int N, K;
int arr[11];

void input() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &K);
}

struct Node {
    int k, cnt;
    bool operator<(const Node& n) const {
        return cnt > n.cnt;
    }
};

void solve() {
    priority_queue<Node> pq;
    pq.push({K, 0});
    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();
        pq.push({0, cur.cnt + cur.k});
        if (cur.k == 0) {
            printf("%d\n", cur.cnt);
            return;
        }
        for (int i = 0; i < N; i++) {
            pq.push({cur.k / arr[i], cur.cnt + cur.k % arr[i]});
        }
    }
}

int T;
int main() {
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        printf("#%d ", i);
        input();
        solve();
    }
}