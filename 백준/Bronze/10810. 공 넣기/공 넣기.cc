#include <iostream>

using namespace std;

int N, M;
int arr[101];
int i, j, k;

void solve() {
    scanf("%d %d", &N, &M);
    while (M--) {
        scanf("%d %d %d", &i, &j, &k);
        for (; i <= j; i++)
            arr[i] = k;
    }
    for (i = 1; i <= N; i++)
        printf("%d ", arr[i]);
}

int main() {
    solve();
}