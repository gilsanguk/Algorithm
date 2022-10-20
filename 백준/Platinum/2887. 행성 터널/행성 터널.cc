#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
int N, x, y, z;

vector<pair<int, int>> graph[3];
vector<pair<int, int>> new_graph[100001];
priority_queue<pair<int, int>> pq;
bool visited[100001];

int prim() {
	int ret = 0;
	pq.push({0, 0});
	while (!pq.empty()) {
		int dist = pq.top().first, curr = pq.top().second;
		pq.pop();
		if (visited[curr]) continue;
		visited[curr] = true;
		ret += -dist;
		for (int i = 0; i < new_graph[curr].size(); i++) {
			int next = new_graph[curr][i].first;
			int	dist = new_graph[curr][i].second;
			if (visited[next]) continue;
			pq.push({ - dist, next });
		}
	}
	return ret;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y >> z;
		graph[0].push_back({ x, i });
		graph[1].push_back({ y, i });
		graph[2].push_back({ z, i });
	}
	for (int i = 0; i < 3; i++) {
		sort(graph[i].begin(), graph[i].end());
		for (int j = 1; j < N; j++) {
			int d = abs(graph[i][j].first - graph[i][j - 1].first);
			int s = graph[i][j].second;
			int e = graph[i][j-1].second;
			new_graph[s].push_back({ e, d });
			new_graph[e].push_back({ s, d });
		}
	}
	cout << prim() << '\n';
}