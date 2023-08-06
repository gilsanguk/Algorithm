#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> stack;

void solve() {
    int cur;
    long long ans = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &cur);
        while (!stack.empty() && stack.back() <= cur) {
            stack.pop_back();
        }
        ans += stack.size();
        stack.push_back(cur);
    }
    printf("%lld", ans);
}

int main() {
    solve();
}