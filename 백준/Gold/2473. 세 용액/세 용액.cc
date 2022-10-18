#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N;
long long arr[100001];
vector<int> ans(3);

void solve() {
	long long ret = 3987654321;
	for (int i = 0; i < N - 2; i++) {
		int l = i+1, r = N-1;
		while (l < r) {
			long long curr_sum = (arr[l] + arr[i] + arr[r]);
			if (ret > abs(curr_sum)) {
				ret = abs(curr_sum);
				ans[0] = arr[i], ans[1] = arr[l], ans[2] = arr[r];
			}
			if (curr_sum == 0) return;
			curr_sum < 0 ? l++ : r--;
		}
	}
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr+N);
	solve();
	for (int i = 0; i < 3; i++)
		cout << ans[i] << " ";
}