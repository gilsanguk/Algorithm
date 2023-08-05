#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[51][51];

void input() {
    scanf("%d %d", &N, &M);
    char c;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            scanf(" %c", &c);
            arr[y][x] = c - '0';
        }
    }
}

bool isPossible(int y, int x, int k) {
    if (arr[y][x] != arr[y + k - 1][x]) return false;
    if (arr[y][x] != arr[y][x + k - 1]) return false;
    if (arr[y][x] != arr[y + k - 1][x + k - 1]) return false;
    return true;
}

int solve() {
    int k = min(N, M);
    for (; k > 1; k--) {
        for (int y = 0; y <= N - k; y++) {
            for (int x = 0; x <= M - k; x++) {
                if (isPossible(y, x, k)) return k * k;
            }
        }
    }
    return 1;
}

int main() {
    input();
    printf("%d", solve());
}