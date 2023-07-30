#include <iostream>
#include <string>

using namespace std;

int N, M;
int arr[4][4];
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

int ans = 0;
bool visited[4][4];
void solve(int y, int x) {
    if (y == N) {
        int sum = 0;
        for (int r = 0; r < N; r++) {
            int tmp = 0;
            for (int c = 0; c < M; c++) {
                if (visited[r][c]) tmp = tmp * 10 + arr[r][c];
                else {
                    sum += tmp;
                    tmp = 0;
                }
            }
            sum += tmp;
        }
        for (int c = 0; c < M; c++) {
            int tmp = 0;
            for (int r = 0; r < N; r++) {
                if (!visited[r][c]) tmp = tmp * 10 + arr[r][c];
                else {
                    sum += tmp;
                    tmp = 0;
                }
            }
            sum += tmp;
        }
        ans = max(ans, sum);
        return;
    }
    if (x == M) {
        solve(y + 1, 0);
        return;
    }
    visited[y][x] = true;
    solve(y, x + 1);
    visited[y][x] = false;
    solve(y, x + 1);
}

int main() {
    input();
    solve(0, 0);
    printf("%d", ans);
}