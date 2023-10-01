#include <iostream>

using namespace std;

int N, S;
int arr[14];
bool count[13 * 200000 + 1];

void input() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        S += arr[i];
    }
}

void backtrack(int n, int sum) {
    if (n > N) return;
    count[sum] = true;
    backtrack(n + 1, sum);
    backtrack(n + 1, sum + arr[n]);
    backtrack(n + 1, abs(sum - arr[n]));
}

void solve() {
    int ans = 0;
    backtrack(0, 0);
    for (int i = 1; i <= S; i++)
        ans += !count[i];
    printf("%d", ans);
}

int main() {
    input();
    solve();
}