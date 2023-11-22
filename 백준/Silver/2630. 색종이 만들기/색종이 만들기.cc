#include <iostream>

using namespace std;

int N;
int arr[129][129];
int blue, white;

void input() {
    scanf("%d", &N);
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            scanf("%d", &arr[y][x]);
}

bool isOneColor(int len, int sy, int sx) {
    for (int y = sy; y < sy + len; y++)
        for (int x = sx; x < sx + len; x++)
            if (arr[y][x] != arr[sy][sx]) return false;

    arr[sy][sx] ? blue++ : white++;

    return true;
}

void divideAndConquer(int len, int sy, int sx) {
    if (isOneColor(len, sy, sx)) return;

    int nLen = len / 2;

    divideAndConquer(nLen, sy, sx);
    divideAndConquer(nLen, sy + nLen, sx);
    divideAndConquer(nLen, sy, sx + nLen);
    divideAndConquer(nLen, sy + nLen, sx + nLen);
}

void solve() {
    divideAndConquer(N, 0, 0);
    printf("%d\n%d", white, blue);
}

int main() {
    input();
    solve();
}