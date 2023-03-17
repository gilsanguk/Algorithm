#include <iostream>
#include <queue>
#include <cstring>
#define MAX 100001

using namespace std;

int N, K;
struct Node{
    int cur, time;
};
queue<Node> q;
int visited[MAX];
int ans = 987654321, cnt = 0;

void bfs() {
    q.push({N, 0});
    while(!q.empty()) {
        Node cur = q.front();
        q.pop();
        if (cur.time > ans) continue;
        if(cur.cur == K) {
            ans = min(ans, cur.time);
            cnt++;
        }
        int tmp[3] = {cur.cur * 2, cur.cur + 1, cur.cur - 1};
        for (int i: tmp) {
            if (i < 0 || i >= MAX || visited[i] < cur.time + 1) continue;
            visited[i] = cur.time + 1;
            q.push({i, cur.time + 1});
        }
    }
}

int main() {
    for (int i = 0; i < MAX; i++) visited[i] = 987654321;
    scanf("%d %d", &N, &K);
    bfs();
    printf("%d\n%d", ans, cnt);
}