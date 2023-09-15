#include <iostream>

using namespace std;

int K, N, M;

void input() {
    scanf("%d %d %d", &K, &N, &M);
}

void solve() {
    printf("%d", K * N < M ? 0 : K * N - M);
}

int main() {
    input();
    solve();
}