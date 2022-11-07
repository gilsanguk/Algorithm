#include <iostream>
#include <map>

using namespace std;
using ll = long long;

int T, N, M;
int A[1001], B[1001];
map<int, int> PsumA;
void solve(){
    ll ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            int sum = A[j+1] - A[i];
            PsumA[sum]++;
        }
    }
    for(int i = 0; i < M; i++){
        for(int j = i; j < M; j++){
            int sum = B[j+1] - B[i];
            ans += PsumA[T-sum];
        }
    }
    printf("%lld", ans);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &T);
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
        A[i] = A[i-1] + A[i];
    }
    scanf("%d", &M);
    for (int i = 1; i <= M; i++) {
        scanf("%d", &B[i]);
        B[i] = B[i - 1] + B[i];
    }
    solve();
}