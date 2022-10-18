#include <iostream>
#include <algorithm>

using namespace std;
int N;
int arr[100001];


int solve() {
	int r = lower_bound(arr, arr + N, 0) - arr;
	if (r == N) r--;
	if (r == 0) r++;
	int l = r - 1;
	int curr_sum = arr[l] + arr[r];
	int ret = abs(curr_sum);
	pair<int, int> ans = { l, r };
	for (int i = l - 1; i <= r; i+=2) {
		if (i < 0 || i + 1 >= N) continue;
		int tmp = arr[i] + arr[i + 1];
		if (ret > abs(tmp)) {
			ret = abs(tmp);
			ans = { i, i+1 };
		}
	}
		
	while (0 <= l && r < N) {
		if (ret == 0) break;
		if (curr_sum < 0) {
			r++;
			if (r == N) break;
			curr_sum = arr[l] + arr[r];
			if (ret > abs(curr_sum)) {
				ret = abs(curr_sum);
				ans = { l, r };
			}
		}
		if (curr_sum > 0) {
			l--;
			if (l == -1) break;
			curr_sum = arr[l] + arr[r];
			if (ret > abs(curr_sum)) {
				ret = abs(curr_sum);
				ans = { l, r };
			}
		}
	}
	cout << arr[ans.first] << ' ' << arr[ans.second];
	return 0;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	solve();
}