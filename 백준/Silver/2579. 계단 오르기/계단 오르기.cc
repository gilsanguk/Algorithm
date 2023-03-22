#include <iostream>
#include <cstring>

using namespace std;

int N;
int arr[301];
int dp[301][3];

int solve(int cur, int cnt) {
	if (cur == N) return 0;
	if (cur > N) return -987654321;
	int& ret = dp[cur][cnt];
	if (ret != -1) return ret;
	ret = solve(cur + 2, 1) + arr[cur + 2];
	if (cnt < 2) ret = max(ret, solve(cur + 1, cnt + 1) + arr[cur + 1]);
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}
	printf("%d", solve(0, 0));
}