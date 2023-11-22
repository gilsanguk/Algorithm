#include <iostream>

using namespace std;

int N;
int arr[65][65];
string ans;

char row[65];
void input() {
    scanf("%d", &N);
    for (int y = 0; y < N; y++) {
        scanf("%s", row);
        for (int x = 0; x < N; x++)
            arr[y][x] = row[x] - '0';
    }
}

bool isOneColor(int len, int sy, int sx) {
    for (int y = sy; y < sy + len; y++)
        for (int x = sx; x < sx + len; x++)
            if (arr[y][x] != arr[sy][sx]) return false;

    ans += arr[sy][sx] ? "1" : "0";

    return true;
}

void divideAndConquer(int len, int sy, int sx) {
    if (isOneColor(len, sy, sx)) return;

    ans += "(";
    int nLen = len / 2;

    divideAndConquer(nLen, sy, sx);
    divideAndConquer(nLen, sy, sx + nLen);
    divideAndConquer(nLen, sy + nLen, sx);
    divideAndConquer(nLen, sy + nLen, sx + nLen);

    ans += ")";
}

void solve() {
    divideAndConquer(N, 0, 0);
    printf("%s", ans.c_str());
}

int main() {
    input();
    solve();
}