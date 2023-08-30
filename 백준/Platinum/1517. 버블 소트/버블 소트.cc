#include <iostream>
#include <vector>
#define MAX 500001

using namespace std;

int N;
int arr[MAX];

void input() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
}

long long ans = 0;
vector<int> merge(vector<int>& l, vector<int>& r) {
    vector<int> ret;
    int i = 0, j = 0;
    while (i < l.size() || j < r.size()) {
        if (i < l.size() && (j == r.size() || l[i] <= r[j])) {
            ret.push_back(l[i++]);
        }
        else {
            if (i != l.size()) ans += l.size() - i;
            ret.push_back(r[j++]);
        }
    }
    return ret;
}

vector<int> mergeSort(int s, int e) {
    if (s == e) return {arr[s]};
    int m = (s + e) / 2;
    vector<int> l = mergeSort(s, m);
    vector<int> r = mergeSort(m + 1, e);
    return merge(l, r);
}

void solve() {
    mergeSort(0, N - 1);
    printf("%lld", ans);
}

int main() {
    input();
    solve();
}