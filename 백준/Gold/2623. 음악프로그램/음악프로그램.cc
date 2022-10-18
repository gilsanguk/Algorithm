#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int N, M, T, S;
int order[1001];
vector<int> ans;
vector<int> graph[1001];


bool solve() {
	queue<int> q;
	
	for (int i = 1; i <= N; i++) {
		if (order[i] == 0) {
			q.push(i);
			ans.push_back(i);
		}
	}
	for (int i = 0; i < N; i++) {
		if (q.empty()) {
			return false;
		}
		int curr = q.front();
		q.pop();
		for (int j = 0; j < graph[curr].size(); j++) {
			int next = graph[curr][j];
			order[next]--;
			if (order[next] == 0) {
				q.push(next);
				ans.push_back(next);
			}
		}
	}
	return true;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> T;
		vector<int> v(T);
		for (int j = 0; j < T; j++) {
			cin >> v[j];
		}
		for (int j = 1; j < v.size(); j++) {
			graph[v[j - 1]].push_back(v[j]);
			order[v[j]]++;
		}
	}
	if (solve()) {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << "\n";
		}
	}
	else cout << 0;
}