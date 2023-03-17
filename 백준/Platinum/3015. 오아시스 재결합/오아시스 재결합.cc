#include <iostream>
#include <vector>

#define ll long long

using namespace std;

struct Human {
    int val, cnt;
};
int N, cur;
ll ans;
vector<Human> stack;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &cur);
        while(!stack.empty() && stack.back().val < cur) {
            ans += stack.back().cnt;
            stack.pop_back();
        }
        if (!stack.empty() && stack.back().val == cur) {
            ans += stack.back().cnt++;
            if (stack.size() > 1) ans++;
        } else {
            if (!stack.empty()) ans++;
            stack.push_back({cur, 1});
        }
    }
    printf("%lld", ans);
}
