#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int INF = 2147483647;
int n, m;
vector<int> arr;
int dp[301][301];
int ans = 0;

int go(int from, int to, int remain) {
	if (!remain) return 0;
	int&ret = dp[from][to];
	if (ret != -1) return ret;
	
	int l = min(from, to), r = max(from, to);
	ret = INF;
	if (r < n) ret = min(ret, go(l, r + 1, remain - 1) + remain * (arr[r + 1] - arr[to]));
	if (l > 0) ret = min(ret, go(r, l - 1, remain - 1) + remain * (arr[to] - arr[l - 1]));
	return ret;
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	arr.resize(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	int start = lower_bound(arr.begin(), arr.end(), 0) - arr.begin();
	
	for (int i = 1; i <= n; i++) {
		memset(dp, -1, sizeof(dp));
		ans = max(ans, i * m - go(start, start, i));
	}
	cout << ans << '\n';
}