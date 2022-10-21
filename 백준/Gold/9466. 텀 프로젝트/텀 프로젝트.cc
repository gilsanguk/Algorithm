#include<iostream>
#include<cstring>

using namespace std;
int T, N;
int arr[1000001];
int prev[1000001];
bool finished[1000001];
bool visited[1000001];
int ans;

void dfs(int u) {
	visited[u] = true;;
	int v = arr[u];
	if (!visited[v]) dfs(v);
	else if (!finished[v]) {
		for (int i = v; i != u; i = arr[i]) ans++;
		ans++;
	}
	finished[u] = true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	cin >> T;
	while (T--){
		cin >> N;
		memset(arr, 0, sizeof(arr));
		memset(visited, false, sizeof(visited));
		memset(finished, false, sizeof(finished));
		ans = 0;
		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
		}
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) dfs(i);
		}
		cout << N - ans << endl;
	}
}