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

int cnt[MAX], cnt2[MAX], ans[MAX];
int mx;
void pl(int x) {
    if (cnt[x] != 0) cnt2[cnt[x]]--;
    cnt[x]++;
    cnt2[cnt[x]]++;
    mx = max(mx, cnt[x]);
}

void mi(int x) {
    if (cnt[x] == mx && cnt2[cnt[x]] == 1) mx--;
    cnt2[cnt[x]]--;
    cnt[x]--;
    cnt2[cnt[x]]++;
}

void solve() {
    sort(query, query + M);
    int s = query[0].s, e = query[0].e;
    for (int i = s; i <= e; i++) {
        if (cnt[arr[i]] != 0) cnt2[cnt[arr[i]]]--;
        cnt[arr[i]]++;
        cnt2[cnt[arr[i]]]++;
        mx = max(mx, cnt[arr[i]]);
    }
    ans[query[0].idx] = mx;
    for (int i = 1; i < M; i++) {
        while(s > query[i].s) pl(arr[--s]);
        while(e < query[i].e) pl(arr[++e]);
        while(s < query[i].s) mi(arr[s++]);
        while(e >query[i].e) mi(arr[e--]);
        ans[query[i].idx] = mx;
    }
    for (int i = 0; i < M; i++)
        printf("%d\n", ans[i]);
}

int main() {
    input();
    solve();
}