#include <iostream>
#include <vector>

using namespace std;

int T, N;
char src[100001];
char dist[100001];

void input() {
    scanf("%d", &N);
    scanf("%s", src);
    scanf("%s", dist);
}

int W, B;
void solve() {
    W = 0, B = 0;
    for (int i = 0; i < N; i++) {
        if (src[i] != dist[i]) {
            if (src[i] == 'W') W++;
            else B++;
        }
    }
    printf("%d\n", max(W, B));
}

int main() {
    scanf("%d", &T);
    while (T--) {
        input();
        solve();
    }
}