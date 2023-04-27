#include <iostream>
#define MAX 751

using namespace std;

int R, C;
int ldp[MAX][MAX], rdp[MAX][MAX];
int ans;

int main() {
    scanf("%d %d", &R, &C);
    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            char a;
            scanf(" %c", &a);
            ldp[y][x] = rdp[y][x] = a - '0';
        }
    }
    for (int y = R - 2; y >= 0; y--) {
        for (int x = 0; x < C; x++) {
            if (ldp[y][x] && x > 0) {
                ldp[y][x] = ldp[y + 1][x - 1] + 1;
            }
            if (rdp[y][x] && x < C - 1) {
                rdp[y][x] = rdp[y + 1][x + 1] + 1;
            }
        }
    }
    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            int n = min(ldp[y][x], rdp[y][x]);
            for (int i = 0; i < n; i++) {
                if (rdp[y + i][x - i] > i && ldp[y + i][x + i] > i) {
                    ans = max(ans, i + 1);
                }
            }
        }
    }
    printf("%d", ans);
}