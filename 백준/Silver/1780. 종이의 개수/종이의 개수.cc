#include <iostream>
#define MAX 2200

using namespace std;

int N;
int arr[MAX][MAX];
int ans[3];

void input() {
    scanf("%d", &N);
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            scanf("%d", &arr[y][x]);
}

bool checkIsOneColor(int n, int sy, int sx) {
    int color = arr[sy][sx];
    for (int y = sy; y < sy + n; y++)
        for (int x = sx; x < sx + n; x++)
            if (arr[y][x] != color) return false;
    return true;
}

void divideAndConquer(int n, int sy, int sx) {
    if (n == 1 || checkIsOneColor(n, sy, sx)) {
        ans[arr[sy][sx] + 1]++;
        return;
    }

    int newN = n / 3;

    for (int i = 0; i < n; i += newN)
        for (int j = 0; j < n; j += newN)
            divideAndConquer(newN, sy + i, sx + j);
}

void solve() {
    divideAndConquer(N, 0, 0);
    printf("%d\n%d\n%d\n", ans[0], ans[1], ans[2]);
}

int main() {
    input();
    solve();
}