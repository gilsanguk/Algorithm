#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;
int N, M;
vector<pair<int, int>> items;
int dp[3011][10001];

int solve(int cur, int capacity) {
	if (cur == N) return 0;
	int& ret = dp[cur][capacity];
	if (ret != -1) return ret;
	int v = items[cur].first, c = items[cur].second;
	ret = solve(cur + 1, capacity);
	if (v <= capacity) ret = max(ret, solve(cur + 1, capacity - v) + c);
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N >> M;
	int v, c, k;
	for (int i = 0; i < N; i++) {
		cin >> v >> c >> k;
		for (int i = k; i > 0; i >>= 1) {
			int tmp = i - (i >> 1);
			items.push_back({ v*tmp, c*tmp });
		}
	}
	N = items.size();
	cout << solve(0, M);
}