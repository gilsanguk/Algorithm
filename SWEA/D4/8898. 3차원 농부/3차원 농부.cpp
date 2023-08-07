#include <iostream>
#include <algorithm>
#define MAX 500001

using namespace std;

int N, M;
int c1, c2;
int cow[MAX], horse[MAX];

void input() {
    scanf("%d %d", &N, &M);
    scanf("%d %d", &c1, &c2);
    for (int i = 0; i < N; i++)
        scanf("%d", &cow[i]);
    sort(cow, cow + N);
}

int binSearch(int val) {
    int l = 0, r = N - 1;
    int mid = (l + r) / 2;
    if (val < cow[l]) return l;
    if (val > cow[r]) return r;
    while (l <= r) {
        mid = (l + r) / 2;
        if (cow[mid] == val) return mid;
        else if (cow[mid] < val) l = mid + 1;
        else r = mid - 1;
    }
    if (cow[mid] < val) mid++;
    return mid;
}

int solve() {
    int ans = 987654321, cnt = 0;
    for (int i = 0; i < M; i++) {
        scanf("%d", &horse[i]);
        int idx = binSearch(horse[i]);
        if (0 <= idx) {
            int c = cow[idx];
            int dist = abs(c - horse[i]);
            if (ans > dist) {
                ans = dist;
                cnt = 1;
            }
            else if (ans == dist) cnt++;
        }
        if (0 < idx) {
            int c = cow[idx - 1];
            int dist = abs(c - horse[i]);
            if (ans > dist) {
                ans = dist;
                cnt = 1;
            }
            else if (ans == dist) cnt++;
        }
    }
    printf("%d %d\n", ans + abs(c1 - c2), cnt);
}

int T;
int main() {
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        input();
        printf("#%d ", i);
        solve();
    }
}