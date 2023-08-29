#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>
#define INF 987654321

using namespace std;

int N;
struct Point {
    int y, x;
    bool operator<(const Point& rhs) const {
        if (y == rhs.y) return x < rhs.x;
        return y < rhs.y;
    }
} arr[100001];
set<Point> s;

void input() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &arr[i].x, &arr[i].y);
    }
}

int getDist(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

void solve() {
    sort(arr, arr + N, [] (const Point& a, const Point& b) {
        if (a.x == b.x) return a.y < b.y;
        return a.x < b.x;
    });
    s.insert({arr[0].y, arr[0].x});
    s.insert({arr[1].y, arr[1].x});
    int ans = getDist(arr[0], arr[1]);
    int start = 0;
    for (int i = 2; i < N; i++) {
        Point cur = arr[i];
        while (start < i) {
            Point p = arr[start];
            int x = cur.x - p.x;
            if (x * x <= ans) break;
            s.erase({p.y, p.x});
            start++;
        }
        int d = sqrt(ans);
        auto lower = s.lower_bound({cur.y - d, -INF});
        auto upper = s.upper_bound({cur.y + d, INF});
        for (auto it = lower; it != upper; it++)
            ans = min(ans, getDist(cur, {it->y, it->x}));
        s.insert({cur.y, cur.x});
    }
    printf("%d", ans);
}

int main() {
    input();
    solve();
}