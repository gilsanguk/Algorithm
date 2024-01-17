#include <iostream>
#include <cstring>
#define INF 987654321

using namespace std;

int N;
int arr[11][11];
int memo[1 << 10];

void input() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &arr[i][j]);
}

int dynamicProgramming(int cur, int visit, int start) {
    if (visit == (1 << N) - 1) {
        return arr[cur][start] != 0 ? arr[cur][start] : INF;
    }

    int& ret = memo[visit] = INF;

    for (int nxt = 0; nxt < N; nxt++) {
        if (cur == -1) {
            ret = min(ret, dynamicProgramming(nxt, 1 << nxt, nxt));
            continue;
        }
        if (arr[cur][nxt] == 0) continue;
        if ((1 << nxt) & visit) continue;

        ret = min(ret, dynamicProgramming(nxt, visit | (1 << nxt), start) + arr[cur][nxt]);
    }
    return ret;
}

void solve() {
    memset(memo, -1, sizeof(memo));
    printf("%d", dynamicProgramming(-1, 0, -1));
}

int main() {
    input();
    solve();
}