#include <iostream>
#include <queue>
#include <cstring>
#define MAX 100001

using namespace std;

int N, K;

void input() {
    scanf("%d %d", &N, &K);
}

int prv[MAX * 2];
queue<int> q;
int bfs() {
    q.push(N);
    int cnt = 0;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            int cur = q.front();
            if (cur == K) return cnt;
            q.pop();
            int tmp[3] = {cur - 1, cur + 1, cur * 2};
            for (int& next : tmp) {
                if (0 > next || next >= MAX * 2) continue;
                if (prv[next] != -1) continue;
                prv[next] = cur;
                q.push(next);
            }
        }
        cnt++;
    }
    return 0;
}

void solve() {
    memset(prv, -1, sizeof(prv));
    printf("%d\n", bfs());
    vector<int> ans;
    for (int i = K; i != N; i = prv[i])
        ans.push_back(i);
    ans.push_back(N);
    for (int i = ans.size() - 1; i > -1; i--)
        printf("%d ", ans[i]);
}

int main() {
    input();
    solve();
}