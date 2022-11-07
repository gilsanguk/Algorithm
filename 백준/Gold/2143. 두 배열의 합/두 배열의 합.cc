#include <iostream>
#include <map>

using namespace std;
using ll = long long;

int T, N, M;
int A[1001], B[1001];
map<int, int> PmapA;
ll solve(){
    ll ret = 0;
    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            int sum = A[j+1] - A[i];
            PmapA[sum]++;
        }
    }
    for(int i = 0; i < M; i++){
        for(int j = i; j < M; j++){
            int sum = B[j+1] - B[i];
            ret += PmapA[T-sum];
        }
    }
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &T);
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
    }
    scanf("%d", &M);
    for (int i = 1; i <= M; i++) {
        scanf("%d", &B[i]);
    }
    for (int i = 1; i <= N; i++) {
        A[i] = A[i-1] + A[i];
    }
    for (int i = 1; i <= M; i++) {
        B[i] = B[i-1] + B[i];
    }
    printf("%lld", solve());
}