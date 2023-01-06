#include <iostream>
#include <map>
#include <vector>

#define turn(x) (x+1) % 4

using namespace std;

int D[4][2] = {{0,  -1},
               {1,  0},
               {0,  1},
               {-1, 0}};
multimap<int, pair<int, int>> percent[4] = {
        {{1, {-1, 1}},  {1, {1,  1}},  {2, {-2, 0}},  {2, {2, 0}}, {5, {0,  -2}}, {7, {-1, 0}},  {7, {1, 0}}, {10, {-1, -1}}, {10, {1,  -1}}},
        {{1, {-1, -1}}, {1, {-1, 1}},  {2, {0,  -2}}, {2, {0, 2}}, {5, {2,  0}},  {7, {0,  -1}}, {7, {0, 1}}, {10, {1,  -1}}, {10, {1,  1}}},
        {{1, {-1, -1}}, {1, {1,  -1}}, {2, {-2, 0}},  {2, {2, 0}}, {5, {0,  2}},  {7, {-1, 0}},  {7, {1, 0}}, {10, {-1, 1}},  {10, {1,  1}}},
        {{1, {1,  -1}}, {1, {1,  1}},  {2, {0,  -2}}, {2, {0, 2}}, {5, {-2, 0}},  {7, {0,  -1}}, {7, {0, 1}}, {10, {-1, -1}}, {10, {-1, 1}}}
};

int N, y, x, dir, movedist = 1;
int arr[1001][1001];

void move() {
    for (int i = 0; i < movedist; i++) {
        y += D[dir][0];
        x += D[dir][1];
        int sand = arr[y][x];
        int remain = arr[y][x];
        arr[y][x] = 0;
        for (auto [k, v]: percent[dir]) {
            int ny = y + v.first;
            int nx = x + v.second;
            remain -= sand * k / 100;
            if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
            arr[ny][nx] += sand * k / 100;
        }
        int ny = y + D[dir][0];
        int nx = x + D[dir][1];
        if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
        arr[ny][nx] += remain;
    }
}

int solve() {
    while (movedist < N) {
        for (int i = 0; i < 2; i++) {
            move();
            dir = turn(dir);
        }
        movedist++;
    }
    move();
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ans += arr[i][j];
        }
    }
    return ans;
}

int main() {
    scanf("%d", &N);
    int total = 0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            scanf("%d", &arr[y][x]);
            total += arr[y][x];
        }
    }
    y = x = N / 2;
    printf("%d", total - solve());
}