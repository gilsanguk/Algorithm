#include <iostream>

using namespace std;

int N, M;
int a, b, c;
int parent[1000001];

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    parent[y] = x;
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if (a) {
            if (find(b) == find(c)) printf("YES\n");
            else printf("NO\n");
        }
        else {
            merge(b, c);
        }
    }
}