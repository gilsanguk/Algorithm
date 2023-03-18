#include <iostream>
#include <vector>

using namespace std;

struct Num {
	int idx, val;

	bool operator<(const Num& rhs) const {
		return val < rhs.val;
	}
};
int N, M;
int arr[10];
vector<int> ans;
Num minZero, minOne;

void solve() {
	ans.push_back(minOne.idx);
	M -= minOne.val;
	while (M >= minZero.val) {
		M -= minZero.val;
		ans.push_back(minZero.idx);
	}
	int cur = 0;
	while (cur != ans.size()) {
		for (int i = N - 1; i >= 0; i--) {
			if (M >= arr[i] - arr[ans[cur]]) {
				M -= arr[i] - arr[ans[cur]];
				ans[cur] = i;
				break;
			}
		}
		cur++;
	}
	for (int i = 0; i < ans.size(); i++) {
		printf("%d", ans[i]);
	}
}

int main() {
	minZero = minOne = { 0, 987654321 };
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		minZero = min(minZero, { i, arr[i] });
		if (i != 0) minOne = min(minOne, { i, arr[i] });
	}
	scanf("%d", &M);
	solve();
}