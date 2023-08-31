#include <iostream>
#include <cstring>

using namespace std;

int N;
int arr[51];

void input() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
}

int memo[51][500001];
int solve(int n, int c) {
    if (n == N) {
        if (c == 0) return 0;
        return -1987654321;
    }
    int& ret = memo[n][c];
    if (ret != -1) return ret;
    ret = solve(n + 1, c);
    ret = max(ret, solve(n + 1, c + arr[n]) + arr[n]);
    if (c < arr[n]) ret = max(ret, solve(n + 1, arr[n] - c) + arr[n] - c);
    else ret = max(ret, solve(n + 1, c - arr[n]));
    return ret;
}

int main() {
    memset(memo, -1, sizeof(memo));
    input();
    int ans = solve(0, 0);
    printf("%d", ans ? ans : -1);
}