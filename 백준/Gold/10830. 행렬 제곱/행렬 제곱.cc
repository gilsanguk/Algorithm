#include <iostream>
#include <vector>
#define ll long long
#define MOD(x) ((x) % 1000)

using namespace std;

int N;
ll B;
vector<vector<int>> A;

void input() {
    scanf("%d %lld", &N, &B);
    A.resize(N);
    for (int i = 0; i < N; i++) {
        A[i].resize(N);
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
        }
    }
}

vector<vector<int>> multiply(vector<vector<int>>& a, vector<vector<int>> &b) {
    vector<vector<int>> ret(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ll tmp = 0;
            for (int k = 0; k < N; k++)
                tmp = MOD(tmp + a[i][k] * b[k][j]);
            ret[i][j] = MOD(tmp);
        }
    }
    return ret;
}

vector<vector<int>> square(vector<vector<int>>& a, ll n) {
    vector<vector<int>> ret(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) ret[i][i] = 1;
    while (n) {
        if (n & 1) {
            ret = multiply(ret, a);
        }
        a = multiply(a, a);
        n >>= 1;
    }
    return ret;
}

void solve() {
    vector<vector<int>> ans = square(A, B);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
}

int main() {
    input();
    solve();
}