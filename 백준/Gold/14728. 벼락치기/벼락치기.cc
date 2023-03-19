#include <iostream>
#include <cstring>

using namespace std;

int N, T;
pair<int, int> arr[101];
int dp[101][10001];

int solve(int n, int t) {
	if (n == N) return 0;
	int& ret = dp[n][t];
	if (ret != -1) return ret;
	ret = solve(n + 1, t);
	if (arr[n].first + t <= T) {
		ret = max(ret, solve(n + 1, t + arr[n].first) + arr[n].second);
	}
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &N, &T);
	for (int i = 0; i < N; i++) scanf("%d %d", &arr[i].first, &arr[i].second);
	printf("%d", solve(0, 0));
}