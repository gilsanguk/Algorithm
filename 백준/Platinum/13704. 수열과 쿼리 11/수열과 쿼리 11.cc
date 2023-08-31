#include <iostream>
#include <cmath>
#include <algorithm>
#define ll long long
#define MAX 100001

using namespace std;

int N, M, K;
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
    scanf("%d %d", &N, &K);
    sqrtN = sqrt(N);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
        arr[i] ^= arr[i-1];
    }
    scanf("%d", &M);
    for(int i = 0; i < M; i++) {
        scanf("%d %d", &query[i].s, &query[i].e);
        query[i].idx = i, query[i].s--;
    }
}

ll cnt[1 << 20];
ll ans[MAX];
ll cur;

void pl (int x) {
    cur += cnt[x^K];
    cnt[x]++;
}

void mi (int x) {
    cnt[x]--;
    cur -= cnt[x^K];
}

void solve() {
    sort(query, query + M);
    int s = query[0].s, e = query[0].e;
    for (int i = s; i <= e; i++) pl(arr[i]);
    ans[query[0].idx] = cur;
    for (int i = 1; i < M; i++) {
        while (query[i].s < s) pl(arr[--s]);
        while (query[i].e > e) pl(arr[++e]);
        while (query[i].s > s) mi(arr[s++]);
        while (query[i].e < e) mi(arr[e--]);
        ans[query[i].idx] = cur;
    }
    for (int i = 0; i < M; i++)
        printf("%lld\n", ans[i]);
}

int main() {
    input();
    solve();
}