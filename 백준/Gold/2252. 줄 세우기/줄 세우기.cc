#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 32001

using namespace std;
int N, M;
int order[MAX_N];
vector<int> graph[MAX_N];
vector<int> ans;

int solve() {
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (order[i] == 0) {
			q.push(i);
			ans.push_back(i);
		}
	}
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (int i = 0; i < graph[curr].size(); i++) {
			int next = graph[curr][i];
			order[next]--;
			if (order[next] == 0) {
				q.push(next);
				ans.push_back(next);
			}
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	return 0;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	cin >> N >> M;
	int s, e;
	for (int i = 0; i < M; i++) {
		cin >> s >> e;
		graph[s].push_back(e);
		order[e]++;
	}
	solve();
}