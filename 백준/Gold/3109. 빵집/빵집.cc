#include <iostream>

using namespace std;

int delta[3][2] = {{-1, 1}, {0, 1}, {1, 1} };
int N, M;
int arr[10001][501];
bool visited[10001][501];

bool dfs(int y, int x) {
	if (x == M - 1) return true;
	visited[y][x] = true;
	for (int i = 0; i < 3; i++) {
		int ny = y + delta[i][0], nx = x + delta[i][1];
		if (0 > ny || ny >= N || 0 > nx || nx >= M) continue;
		if (visited[ny][nx] || arr[ny][nx]) continue;
		if (dfs(ny, nx)) return true;
	}
	return false;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			char a;
			scanf(" %c", &a);
			arr[y][x] = a == '.' ? 0 : 1;
		}
	}
	int ans = 0;
	for (int y = 0; y < N; y++) {
		if (dfs(y, 0)) ans++;
	}
	printf("%d", ans);
}