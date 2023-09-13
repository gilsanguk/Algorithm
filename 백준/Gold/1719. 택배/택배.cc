#include <iostream>
#include <vector>
#define INF 987654321

using namespace std;

int N, M;
struct Node {
    int n, w;
};
int dist[201][201];

int s, e, w;
int ans[201][201];
void input() {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            dist[i][j] = INF;
    for (int i = 1; i <= N; i++)
        dist[i][i] = 0;
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &s, &e, &w);
        dist[s][e] = w;
        dist[e][s] = w;
        ans[s][e] = e;
        ans[e][s] = s;
    }
}

void solve() {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    ans[i][j] = ans[i][k];
                }
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (ans[i][j] == 0) printf("- ");
            else printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
}

int main() {
    input();
    solve();
}