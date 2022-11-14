#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 987654321

using namespace std;

int T, K;
int arr[501];
int Psum[501];
int dp[501][501];

int solve(int s, int e) {
	if (s == e) return 0;
	int& ret = dp[s][e];
	if (ret != -1) return ret;
	ret = MAX;
	for (int i = s; i < e; i++) {
		ret = min(ret, solve(s, i) + solve(i + 1, e) + Psum[e + 1] - Psum[s]);
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &T);
	while(T--) {
		memset(dp, -1, sizeof(dp));
		scanf("%d", &K);
		for (int i = 0; i < K; i++) {
			scanf("%d", &arr[i]);
		}
		Psum[0] = 0;
		for (int i = 0; i < K; i++) {
			Psum[i + 1] = Psum[i] + arr[i];
		}
		printf("%d\n", solve(0, K - 1));
	}
}