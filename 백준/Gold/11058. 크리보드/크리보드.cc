#include <iostream>
#define ll long long

using namespace std;

int N;

ll memo[101];
void solve() {
    for (int i = 1; i < 7; i++) memo[i] = i;
    for (int i = 7; i <= N; i++)
        for (int j = 3; i - j > 0; j++)
            memo[i] = max(memo[i], memo[i - j] * (j - 1));
    printf("%lld", memo[N]);
}

int main() {
    scanf("%d", &N);
    solve();
}