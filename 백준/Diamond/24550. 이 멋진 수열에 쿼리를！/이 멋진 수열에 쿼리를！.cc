#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <unordered_map>
#define K 1000000007
#define MOD(x) (x+K)%K
#define MAX 1000500
#define ll long long
using namespace std;

ll N, Q;
ll Query[MAX][2];
typedef vector<vector<ll>> matrix;
matrix mat = { {1, 1, 0}, {1, 0, 0}, {0, 0, 1} };
vector<matrix> arr;
matrix tree[MAX*4];
vector<ll> section = {1};
set<ll> qs;
unordered_map<ll, ll> id_map;

matrix operator*(const matrix& a, const matrix& b) {
    matrix c(3, vector<ll>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                c[i][j] += MOD(a[i][k] * b[k][j]);
            }
            c[i][j] = MOD(c[i][j]);
        }
    }
    return c;
}

matrix pow(matrix a, ll n) {
    matrix b(3, vector<ll>(3));
    for (int i = 0; i < 3; i++) {
        b[i][i] = 1;
    }
    while (n > 0) {
        if (n & 1) b = b * a;
        a = a * a;
        n >>= 1;
    }
    return b;
}

void init(int node, int s, int e) {
    if (s == e) tree[node] = arr[s];
    else {
        int mid = (s + e) >> 1;
        init(node << 1, s, mid);
        init(node << 1 | 1, mid + 1, e);
        tree[node] = tree[node << 1 | 1] * tree[node << 1];
    }
}

void update(int node, int s, int e, int idx, matrix& value){
    if (idx < s || e < idx) return;
    if (s == e) tree[node] = value;
    else {
        int mid = (s + e) >> 1;
        update(node << 1, s, mid, idx, value);
        update(node << 1 | 1, mid + 1, e, idx, value);
        tree[node] = tree[node << 1 | 1] * tree[node << 1];
    }
}

void solve() {
    for (ll pos: qs) {
        section.push_back(pos);
    }
    sort(section.begin(), section.end());
    for (int i = 1; i < section.size(); i++) {
        ll diff = section[i] - section[i - 1];
        if (diff > 1) {
            arr.push_back(pow(mat, diff - 1));
        }
        arr.push_back(pow(mat, 1));
        id_map.insert({section[i], arr.size()-1});
    }
    arr.push_back(pow(mat, N - section[section.size() - 1]));
    init(1, 0, arr.size()-1);
    for (int i = 1; i <= Q; i++) {
        arr[id_map.at(Query[i][0])] = {{0, 0, Query[i][1]}, {1, 0, 0}, {0, 0, 1}};
        update(1, 0, arr.size() - 1, id_map.at(Query[i][0]), arr[id_map.at(Query[i][0])]);
        matrix ans = tree[1];
        cout << MOD(ans[0][0] + ans[0][2]) << "\n";
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N >> Q;
    for (int i = 1; i <= Q; i++) {
        cin >> Query[i][0] >> Query[i][1];
        qs.insert(Query[i][0]);
    }
    solve();
}