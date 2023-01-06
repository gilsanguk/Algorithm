#include <iostream>
#include <vector>
#include <algorithm>
#define pairV vector<pair<int, int>>

using namespace std;

int N, M;
int arr[51][51];
int d, s;
int dy[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dx[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
pairV pre;
pairV cur;

void move() {
    cur.clear();
    pairV::iterator iter;
    for (iter = pre.begin(); iter != pre.end(); iter++) {
        auto [y, x] = *iter;
        int ny = y + dy[d] * s;
        int nx = x + dx[d] * s;
        if (ny > N) ny %= N;
        if (nx > N) nx %= N;
        if (ny < 1) ny = N + ny % N;
        if (nx < 1) nx = N + nx % N;
        cur.push_back({ ny, nx });
        arr[ny][nx]++;
    }
    for (iter = cur.begin(); iter != cur.end(); iter++) {
        auto [y, x] = *iter;
        for (int i = 2; i <= 8; i += 2) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 1 || nx < 1 || ny > N || nx > N) continue;
            if (arr[ny][nx] > 0) arr[y][x]++;
        }
    }
    pre.clear();
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            if (arr[y][x] > 1 && find(cur.begin(), cur.end(), make_pair(y, x)) == cur.end()) {
                pre.push_back({ y, x });
                arr[y][x] -=2;
            }
        }
    }
}


int main() {
    scanf("%d %d", &N, &M);
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            scanf("%d", &arr[y][x]);
        }
    }
    pre = {{N, 1}, {N,2}, {N-1, 1}, {N-1, 2}};
    for (int i = 0; i < M; i++){
        scanf("%d %d", &d, &s);
        move();
    }
    int ans = 0;
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            ans += arr[y][x];
        }
    }
    printf("%d", ans);
}