#include <iostream>
#include <vector>
#include <map>
#define x first
#define y second

using namespace std;
using line = pair<int, int>;

int N;
vector<pair<line, line>> lines;
int rep[3001];
map<int, int> count;

int find(int x) {
    if (rep[x] == x) return x;
    return rep[x] = find(rep[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    rep[x] = y;
}

int ccw(pair<int,int> a, pair<int,int> b, pair<int,int> c){
    int ret = a.x*b.y + b.x*c.y + c.x*a.y;
    ret -= (a.y*b.x + b.y*c.x + c.y*a.x);
    if (ret > 0) return 1;
    if (ret == 0) return 0;
    return -1;
}

bool solve(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d){
    int ab = ccw(a, b, c) * ccw(a, b, d);
    int cd = ccw(c, d, a) * ccw(c, d, b);
    if (ab == 0 && cd == 0) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        return c <= b && a <= d;
    }
    return ab <= 0 && cd <= 0;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        lines.push_back({{x1, y1}, {x2, y2}});
    }
    for (int i = 0; i < N; i++) {
        rep[i] = i;
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (solve(lines[i].x, lines[i].y, lines[j].x, lines[j].y)) {
                merge(i, j);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        count[find(i)]++;
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, count[find(i)]);
    }
    printf("%d\n%d", count.size(), ans);
}