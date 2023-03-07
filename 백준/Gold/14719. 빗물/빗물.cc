#include <iostream>

using namespace std;

int N, M;
int arr[501];

int solve() {
    int ret = 0;
    for (int i = 1; i < M - 1; i++) {
        int l = 0, r = 0;
        for (int j = 0; j < i; j++) l = max(l, arr[j]);
        for (int j = M - 1; j > i; j--) r = max(r, arr[j]);
        ret += max(0, min(l, r) - arr[i]);
    }
    return ret;
}

int main() {
    scanf("%d %d", &N, &M);
    for (int x = 0; x < M; x++) {
        scanf("%d", &arr[x]);
    }
    printf("%d", solve());
}