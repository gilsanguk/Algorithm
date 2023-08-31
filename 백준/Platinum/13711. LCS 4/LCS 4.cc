#include <iostream>
#include <vector>
#define MAX 100001

using namespace std;

int N;
int A[MAX], B[MAX];

void input() {
   scanf("%d", &N);
   for (int i = 0; i < N; i++) scanf("%d", &A[i]);
   for (int i = 0; i < N; i++) scanf("%d", &B[i]);
}

vector<int> v;
int lis() {
    v.push_back(-1);
    for (int i = 0; i < N; i++) {
        if (v.back() < A[i]) v.push_back(A[i]);
        else {
            auto it = lower_bound(v.begin(), v.end(), A[i]);
            *it = A[i];
        }
    }
    return v.size() - 1;
}

int idx[MAX];
void solve() {
    for (int i = 0; i < N; i++) idx[B[i]] = i;
    for (int i = 0; i < N; i++) A[i] = idx[A[i]];
    printf("%d", lis());
}

int main() {
    input();
    solve();
}