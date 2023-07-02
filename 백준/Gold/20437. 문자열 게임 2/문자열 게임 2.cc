#include <iostream>
#include <cstring>

using namespace std;

int T, K, N;
char W[10001];
int cnt[26];

int getLen(int x) {
    int wordCnt = 0, len = 0;
    while (true) {
        if (W[x + len] == W[x]) wordCnt++;
        if (wordCnt == K) break;
        if (x + len >= N) return -1;
        len++;
    }
    return len + 1;
}

void solve() {
    scanf("%d", &T);
    while (T--) {
        int minV = 10001, maxV = 0;
        scanf("%s", W);
        scanf("%d", &K);
        memset(cnt, 0, sizeof(cnt));
        N = strlen(W);
        for (int i = 0; i < N; i++) {
            cnt[W[i] - 'a']++;
        }
        for (int i = 0; i < N; i++) {
            if (cnt[W[i] - 'a'] < K) continue;
            int tmp = getLen(i);
            if (tmp != -1) {
                minV = min(minV, tmp);
                maxV = max(maxV, tmp);
            }
        }
        if (maxV == 0) printf("%d\n", -1);
        else printf("%d %d\n", minV, maxV);
    }
}

int main() {
    solve();
}