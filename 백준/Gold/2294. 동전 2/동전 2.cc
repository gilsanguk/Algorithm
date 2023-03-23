#include <iostream>
#include <cstring>

using namespace std;

int N, K;
int arr[101];
int dp[101][10001];

int solve(int n, int k) {
	if (k == K) return 0;
	if (n == N) return 987654321;
	int& ret = dp[n][k];
	if (ret != -1) return ret;
	ret = solve(n + 1, k);
	if (k + arr[n] <= K) ret = min(ret, solve(n, k + arr[n]) + 1);
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	int ans = solve(0, 0);
	printf("%d", ans == 987654321 ? -1:ans );
}