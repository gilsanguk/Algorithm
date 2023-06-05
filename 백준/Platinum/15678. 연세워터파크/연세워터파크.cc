#include <iostream>
#include <deque>
#define MAX 100001

using namespace std;
using ll = long long;

int N, D;
int arr[MAX];
struct Node {
    int idx;
    ll val;
};
// LDS 최장 감소 배열
deque<Node> dq;
// dp[i] = i번이 도착점인 최적 경로
ll dp[MAX];

void solve() {
    ll ans = -1987654321;
    for (int i = 0; i < N; i++) {
        dp[i] = arr[i];
        // i - D 보다 작으면 건너뛸 수 없음
        while (!dq.empty() && dq.front().idx < i - D) {
            dq.pop_front();
        }
        // LDS 의 첫 원소는 최대값
        if (!dq.empty()) dp[i] = max(dp[i], dq.front().val + dp[i]);
        // LDS 배열 정리
        while (!dq.empty() && dq.back().val < dp[i]) {
            dq.pop_back();
        }
        dq.push_back({i, dp[i]});
        ans = max(ans, dp[i]);
    }
    printf("%lld", ans);
}

int main() {
    scanf("%d %d", &N, &D);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    solve();
}