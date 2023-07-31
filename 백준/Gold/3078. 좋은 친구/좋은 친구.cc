#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

int N, K;
int memo[21];
deque<string> dq;

void solve() {
    long long ans = 0;
    scanf("%d %d", &N, &K);
    char c[21];
    for (int i = 0; i < N; i++) {
        scanf("%s", c);
        int n = strlen(c);
        string str(c);
        dq.push_back(str);
        ans += memo[n]++;
        if (dq.size() > K) {
            memo[dq.front().size()]--;
            dq.pop_front();
        }
    }
    printf("%lld", ans);
}

int main() {
    solve();
}