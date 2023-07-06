#include <iostream>
#include <queue>
#define MAX 100001

using namespace std;

int N;
priority_queue<int, vector<int>, greater<>> pq;

void solve() {
    scanf("%d", &N);
    int a;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &a);
        pq.push(a);
    }
    int ans = 0;
    while (pq.size() > 1) {
        a = pq.top();
        pq.pop();
        a += pq.top();
        pq.pop();
        ans += a;
        pq.push(a);
    }
    printf("%d", ans);
}

int main() {
    solve();
}