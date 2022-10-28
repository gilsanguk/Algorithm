#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, Q;
int rep[200001];
int p[200001];
int tree[400001][3];

int find_set(int x) {
	if (rep[x] == x) return x;
	return rep[x] = find_set(rep[x]);
}

void merge(int x, int y) {
	rep[find_set(y)] = find_set(x);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> Q;
	for (int i = 2; i <= N; i++) {
		cin >> p[i];
	}
	for (int i = 1; i <= N; i++) rep[i] = i;

	for (int i = 0; i < N + Q - 1; i++) {
		cin >> tree[i][0];
		if (tree[i][0] == 0) cin >> tree[i][1];
		else cin >> tree[i][1] >> tree[i][2];
	}

	vector<bool> ans(Q);
	int idx = 0;
	for (int i = N + Q - 2; i >= 0; i--) {
		if (tree[i][0] == 0) merge(tree[i][1], p[tree[i][1]]);
		else ans[idx++] = (find_set(tree[i][1]) == find_set(tree[i][2]));
	}
	for (int i = Q-1; i >= 0; i--) {
		if (ans[i]) cout << "YES\n";
		else cout << "NO\n";
	}
}