#include <iostream>
#include <queue>
#define MOD(x) ((x) % 20171109)

using namespace std;

int N, A, X, Y;

priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<>> minHeap;

void init() {
    maxHeap = priority_queue<int>();
    minHeap = priority_queue<int, vector<int>, greater<>>();
}

void solve() {
    long long ans = 0;
    scanf("%d %d", &N, &A);
    maxHeap.push(A);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &X, &Y);
        if (maxHeap.top() < X) minHeap.push(X);
        else maxHeap.push(X);
        if (maxHeap.top() < Y) minHeap.push(Y);
        else maxHeap.push(Y);
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        ans = MOD(ans + maxHeap.top());
    }
    printf("%lld\n", ans);
}

int T;
int main() {
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        printf("#%d ", i);
        init();
        solve();
    }
}