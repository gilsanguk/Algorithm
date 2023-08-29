#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
vector<int> graph[1001];
struct Shark {
    int s, v, i;
} arr[51];

void input() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d %d %d", &arr[i].s, &arr[i].v, &arr[i].i);
    }
}

int matched[1001];
bool visited[1001];
int dfs(int x) {
    for (int nx: graph[x]) {
        if (visited[nx]) continue;
        visited[nx] = true;
        if (!matched[nx] || dfs(matched[nx])) {
            matched[nx] = x;
            return 1;
        }
    }
    return 0;
}

void solve() {
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (arr[i].s == arr[j].s && arr[i].v == arr[j].v && arr[i].i == arr[j].i)
                graph[i].push_back(j);
            else if (arr[i].s >= arr[j].s && arr[i].v >= arr[j].v && arr[i].i >= arr[j].i)
                graph[i].push_back(j);
            else if (arr[i].s <= arr[j].s && arr[i].v <= arr[j].v && arr[i].i <= arr[j].i)
                graph[j].push_back(i);
        }
    }
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 2; j++) {
            memset(visited, false, sizeof(visited));
            cnt += dfs(i);
        }
    }
    printf("%d", N - cnt);
}

int main() {
    input();
    solve();
}