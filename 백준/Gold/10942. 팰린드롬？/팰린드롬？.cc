#include<iostream>
#include<cstring>

using namespace std;
int N, M, S, E;
int arr[2001];
int dp[2001][2001];

int palindrom(int s, int e) {
	int& ret = dp[s][e];
	if (arr[s] != arr[e]) return ret = 0;
	if (ret != -1) return ret;
	ret = 1;
	if (s + 1 < e - 1) {
		ret = palindrom(s + 1, e - 1);
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	cin >> M;
	while (M--) {
		cin >> S >> E;
		cout << palindrom(S, E) << '\n';
	}
}