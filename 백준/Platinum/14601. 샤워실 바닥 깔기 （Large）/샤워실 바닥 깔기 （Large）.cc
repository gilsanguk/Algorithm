#include <iostream>

using namespace std;

int K, X, Y, N;
int arr[1 << 7][1 << 7];
int cnt;

bool haveHole(int x1, int y1, int x2, int y2) {
    for (int y = y1; y < y2; y++) {
        for (int x = x1; x < x2; x++) {
            if (arr[y][x] != 0) return true;
        }
    }
    return false;
}

void solve(int sx, int sy, int n) {
    cnt++;
    int nextN = n >> 1;
    if (!haveHole(sx, sy, sx + nextN, sy + nextN)) {
        arr[sy + nextN - 1][sx + nextN - 1] = cnt;
    }
    if (!haveHole(sx + nextN, sy, sx + nextN * 2, sy + nextN)) {
        arr[sy + nextN - 1][sx + nextN] = cnt;
    }
    if (!haveHole(sx, sy + nextN, sx + nextN, sy + nextN * 2)) {
        arr[sy + nextN][sx + nextN - 1] = cnt;
    }
    if (!haveHole(sx + nextN, sy + nextN, sx + nextN * 2, sy + nextN * 2)) {
        arr[sy + nextN][sx + nextN] = cnt;
    }

    if (nextN == 1) return;

    solve(sx, sy, nextN);
    solve(sx + nextN, sy, nextN);
    solve(sx, sy + nextN, nextN);
    solve(sx + nextN, sy + nextN, nextN);
}

int main() {
    scanf("%d", &K);
    scanf("%d %d", &X, &Y);
    N = 1 << K;
    X -= 1, Y = N - Y;
    arr[Y][X] = -1;
    solve(0, 0, N);
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            printf("%d ", arr[y][x]);
        }
        printf("\n");
    }
}