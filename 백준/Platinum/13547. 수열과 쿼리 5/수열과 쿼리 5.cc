#include <iostream>
#include <cmath>
#include <algorithm>
#define MAX 100001

using namespace std;

int N, M;
int arr[MAX];
int sqrtN;
struct Query {
    int idx, s, e;
    bool operator<(const Query &q) const {
        if(s / sqrtN != q.s / sqrtN) return s / sqrtN < q.s / sqrtN;
        return e < q.e;
    }
} query[MAX];

void input() {
    scanf("%d", &N);
    sqrtN = sqrt(N);
    for(int i = 1; i <= N; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &M);
    for(int i = 0; i < M; i++) {
        scanf("%d %d", &query[i].s, &query[i].e);
        query[i].idx = i;
    }
}

int cnt[MAX * 10];
int ans[MAX];
int cur;
void pl(int idx) {
    cnt[arr[idx]]++;
    if(cnt[arr[idx]] == 1) cur++;
}

void mi(int idx) {
    cnt[arr[idx]]--;
    if(cnt[arr[idx]] == 0) cur--;
}

void solve() {
    sort(query, query + M);
    int s = query[0].s, e = query[0].e;
    for (int i = s; i <= e; i++) {
        if(cnt[arr[i]] == 0) cur++;
        cnt[arr[i]]++;
    }
    ans[query[0].idx] = cur;
    for (int i = 1; i < M; i++) {
        while(query[i].s < s) pl(--s);
        while(e < query[i].e) pl(++e);
        while(s < query[i].s) mi(s++);
        while(query[i].e < e) mi(e--);
        ans[query[i].idx] = cur;
    }
    for (int i = 0; i < M; i++)
        printf("%d\n", ans[i]);
}

int main() {
    input();
    solve();
}