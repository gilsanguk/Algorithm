#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int T, N;
struct Node {
    int y;
    int x;
};
Node star;
Node dist;
queue<Node> Q;
Node arr[101];
bool visited[101];

void init() {
    memset(arr, 0, sizeof(arr));
    memset(visited, false, sizeof(arr));
    Q = queue<Node>();
}

bool BFS() {
    Q.push(star);
    while (!Q.empty()) {
        Node curr = Q.front();
        Q.pop();
        if (abs(curr.x - dist.x) + abs(curr.y - dist.y) <= 1000) return true;
        for (int i = 0; i < N; i++) {
            if (abs(curr.x - arr[i].x) + abs(curr.y - arr[i].y) <= 1000 && !visited[i]) {
                visited[i] = true;
                Q.push(arr[i]);
            }
        }
    }
    return false;
}

int main() {
    scanf("%d", &T);
    while(T--) {
        init();
        scanf("%d", &N);
        scanf("%d %d", &star.x, &star.y);
        star.x += 32768;
        star.y += 32768;
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &arr[i].x, &arr[i].y);
            arr[i].x += 32768;
            arr[i].y += 32768;
        }
        scanf("%d %d", &dist.x, &dist.y);
        dist.x += 32768;
        dist.y += 32768;
        if (BFS()) {
          printf("happy\n");
        } else {
          printf("sad\n");
        }
    }
}