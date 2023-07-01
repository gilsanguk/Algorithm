#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
int arr[301];
int l, r, m;

bool isPossible(int x) {
    int sum = 0, cnt = 1;
    for (int i = 0; i < N; i++) {
        sum += arr[i];
        if (sum > x) {
            sum = arr[i];
            cnt++;
        }
    }
    return cnt <= M;
}

void printAns(int ans) {
    printf("%d\n", ans);
    int sum = 0, cnt = 0;
    for (int i = 0; i < N; i++) {
        sum += arr[i];
        if (sum > ans) {
            printf("%d ", cnt);
            sum = arr[i];
            M--;
            cnt = 0;
        }
        cnt++;
        if (N - i == M) break;
    }
    while (M--) {
        printf("%d ", cnt);
        cnt = 1;
    }
}

void solve() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        l = max(l, arr[i]);
        r += arr[i];
    }
    while (l < r) {
        m = (l + r) / 2;
        if (isPossible(m)) r = m;
        else l = m + 1;
    }
    printAns(r);
}

int main() {
    solve();
}