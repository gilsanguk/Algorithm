#include <iostream>
#include <cstring>

using namespace std;

int A, B, C;

int memo[21][21][21];
int solve(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a > 20 || b > 20 || c > 20) return solve(20, 20, 20);
    int& ret = memo[a][b][c];
    if (ret != -1) return ret;
    if (a < b && b < c)
        ret = solve(a, b, c - 1) + solve(a, b - 1, c - 1) - solve(a, b - 1, c);
    else
        ret = solve(a - 1, b, c) + solve(a - 1, b - 1, c) + solve(a - 1, b, c - 1) - solve(a - 1, b - 1, c - 1);
    return ret;
}

int main() {
    memset(memo, -1, sizeof(memo));
    while (true) {
        scanf("%d %d %d", &A, &B, &C);
        if (A == -1 && B == -1 && C== -1) break;
        printf("w(%d, %d, %d) = %d\n", A, B, C, solve(A, B, C));
    }
}